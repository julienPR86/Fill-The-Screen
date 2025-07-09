#ifndef _LABEL_H_
#define _LABEL_H_

#include "../color.h"
#include "SDL3/SDL.h"

//label structure
typedef struct Label
{
    //The element rect, contains the x, y, width and height values
    UI_Element rect;
    //label text
    char *text;
    //label font
    int font_size;
    //text color
    Color text_color;
    //label surface, needs to be null at declaration, will update in label_init
    SDL_Surface *surface;
    //label texture, needs to be null at declaration, will update in label_init
    SDL_Texture *texture;
    //tells if the surface and textures needs to be updated, if the text changed for example
    int update;
    //a local scale which tells to update the label if SCALE has changed
    float local_scale;
    //is active parameter
    int active;
} Label;

//Set the label fields based on te values passed in
Label *label_set_fields(Label *label, char text[], int font_size, Color text_color, int update, float local_scale, int active);
//label init, needs to be called before all label functions
Label *label_init(Label *label, float scale_x, float scale_y);
//update label
void label_update(Label *label, float scale_x, float scale_y);
//render label
void label_render(Label *label, float scale_x, float scale_y);
//free a label
void label_free(Label *label);
//free a label list
void label_list_free(Label *labels[], int size);
//Center the label inside the rect passed in
void label_center(Label *label, UI_Element *rect, float scale_x, float scale_y);

#endif