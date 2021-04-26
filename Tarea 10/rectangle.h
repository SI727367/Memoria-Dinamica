#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <stdlib.h>
#include <math.h>

typedef struct rectangle{
    float base;
    float height;
} *rectangle;

float base(rectangle r){
    return r -> base;
}

float height(rectangle r){
    return r -> height;
}

float area(rectangle r){
    return (r -> base * r -> height);
}

float perimeter(rectangle r){
    return (2*r -> base + 2*r -> height);
}

void set_base(rectangle r, float x){
    r -> base = x;
}

void set_height(rectangle r, float x){
    r -> height = x;
}

rectangle new_rectangle(float b, float h){
    rectangle r = malloc(sizeof(rectangle));
    r -> base = b;
    r -> height = h;
    return r;
}
#endif /* VEC3_H_ */