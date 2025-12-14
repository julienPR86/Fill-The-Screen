#ifndef LABEL_H
#define LABEL_H

#include "../color.h"
#include "SDL3/SDL.h"

//label structure
typedef struct Label
{
    //The label rect, contains the position and the dimensions
    UI_Element rect;
    //The label text
    char *text;
    //The label font size
    int font_size;
    //The text color
    Color text_color;
    //Label surface, needs to be null at declaration, will be updated at initialisation
    SDL_Surface *surface;
    //Label texture, needs to be null at declaration, will be updated at initialisation
    SDL_Texture *texture;
    //Tells if the label surface and texture need to be updated
    t_uint8 update;
    //A local scale used to updated the label if the global scale has changed
    float local_scale;
    //Tells if the label is active or not
    t_uint8 active;
} Label;

//Set the label fields based on te values passed in
Label *label_set_fields(Label *label, char text[], int font_size, Color text_color, t_uint8 update, float local_scale, t_uint8 active);
//label init, needs to be called before all label functions, except for label_set_fields()
Label *label_init(Label *label, float scale_x, float scale_y);
//Updates the label passed in
void label_update(Label *label, float scale_x, float scale_y);
//Render the label passed in
void label_render(Label *label, float scale_x, float scale_y);
//Frees allocated ressources of the label passed in
void label_free(Label *label);
//Frees an array of labels
void label_list_free(Label *labels[], int size);
//Center the label inside the rect passed in
void label_center(Label *label, UI_Element *rect, float scale_x, float scale_y);
//Updates and renders an array of labels
int label_list_update_and_render(Label *labels[], int count);

#endif