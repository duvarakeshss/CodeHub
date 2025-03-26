void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    float delta_x = (Re_max - Re_min) / SCREEN_WIDTH;
    float delta_y = (Im_max - Im_min) / SCREEN_HEIGHT;
    
    glBegin(GL_POINTS);
    for (int i = 0; i < SCREEN_WIDTH; i++) {
        float real = Re_min + i * delta_x;
        for (int j = 0; j < SCREEN_HEIGHT; j++) {
            float imag = Im_min + j * delta_y;
            int gray = mandelbrot(real, imag);
            float color = gray / 255.0f;  
            glColor3f(color, color, color);
            glVertex2f(i, j);
        }
    }
    glEnd();
    
    glFlush();
}
