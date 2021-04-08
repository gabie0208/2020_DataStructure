#include <stdio.h>
#define FALSE 0
#define TRUE 1

struct Rectangle {
    float width;
    float height;
};

struct Rectangle r1, r2;
r1.width = 3.0;
r1.height = 4.0;
r2.width = 6.0;
r2.height = 8.0;

void setWidth(struct Rectangle *r, float w) {
    r->width = w;
}
void setHeight(struct Rectangle *r, float h) {
    r->height = h;
}
void resize(struct Rectangle *r, float ratio) {
    r->width = r->width*ratio;
    r->height = r->height*ratio;
}

float getArea(struct Rectangle r) {
    return r.width*r.height;
}
int isEqual(struct Rectangle r1, struct Rectangle r2) {
    if(r1.width == r2.width && r1.height == r2.height) return TRUE;
    else return FALSE;
}
