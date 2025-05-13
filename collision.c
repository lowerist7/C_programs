#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PARTICLES 20

typedef struct {
    float x, y;
    float vx, vy;
    float radius;
    float mass;
} Particle;

Particle particles[NUM_PARTICLES];

void init_particles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x = rand() % (WIDTH - 40) + 20;
        particles[i].y = rand() % (HEIGHT - 40) + 20;
        particles[i].vx = ((float)(rand() % 200) - 100) / 50;
        particles[i].vy = ((float)(rand() % 200) - 100) / 50;
        particles[i].radius = 10;
        particles[i].mass = 1.0f;
    }
}

void update_positions(float dt) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        particles[i].x += particles[i].vx * dt;
        particles[i].y += particles[i].vy * dt;

        // Bounce off walls
        if (particles[i].x - particles[i].radius < 0 || particles[i].x + particles[i].radius > WIDTH)
            particles[i].vx *= -1;
        if (particles[i].y - particles[i].radius < 0 || particles[i].y + particles[i].radius > HEIGHT)
            particles[i].vy *= -1;
    }
}

void check_collisions() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        for (int j = i + 1; j < NUM_PARTICLES; j++) {
            float dx = particles[j].x - particles[i].x;
            float dy = particles[j].y - particles[i].y;
            float dist = sqrtf(dx * dx + dy * dy);
            float min_dist = particles[i].radius + particles[j].radius;

            if (dist < min_dist) {
                // Normalize
                float nx = dx / dist;
                float ny = dy / dist;

                // Relative velocity
                float vx_rel = particles[i].vx - particles[j].vx;
                float vy_rel = particles[i].vy - particles[j].vy;

                float vel_along_normal = vx_rel * nx + vy_rel * ny;

                if (vel_along_normal > 0) continue;

                // Impulse
                float impulse = (2 * vel_along_normal) / (particles[i].mass + particles[j].mass);

                particles[i].vx -= impulse * particles[j].mass * nx;
                particles[i].vy -= impulse * particles[j].mass * ny;
                particles[j].vx += impulse * particles[i].mass * nx;
                particles[j].vy += impulse * particles[i].mass * ny;

                // Separate the particles slightly to avoid overlap
                float overlap = 0.5f * (min_dist - dist + 1);
                particles[i].x -= overlap * nx;
                particles[i].y -= overlap * ny;
                particles[j].x += overlap * nx;
                particles[j].y += overlap * ny;
            }
        }
    }
}

void draw_particles(SDL_Renderer *renderer) {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int w = 0; w < particles[i].radius * 2; w++) {
            for (int h = 0; h < particles[i].radius * 2; h++) {
                int dx = particles[i].radius - w;
                int dy = particles[i].radius - h;
                if ((dx * dx + dy * dy) <= (particles[i].radius * particles[i].radius)) {
                    SDL_RenderDrawPoint(renderer, particles[i].x + dx, particles[i].y + dy);
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    init_particles();

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Particle Collision Simulator",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    SDL_Event event;

    Uint32 last_time = SDL_GetTicks();

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        Uint32 current_time = SDL_GetTicks();
        float dt = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        update_positions(dt);
        check_collisions();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Background black
        SDL_RenderClear(renderer);

        draw_particles(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
