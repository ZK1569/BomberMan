#include "menu.h"

void init_menu(Game *game)
{
}

void add_menu_option(Game *game, Menu *menu, char *text, int x, int y, int width, int height, int font_size, SDL_Color color, SDL_Color hover_color, SDL_Color active_color, void (*callback)(Game *game))
{
    MenuOption *option = malloc(sizeof(MenuOption));
    option->text = text;
}

void update_menu(Game *game)
{
}

void update_menu_options(Game *game, Menu *menu)
{
}

void update_menu_option(Game *game, Menu *menu, MenuOption *option)
{
}

void render_menu(Game *game)
{
    render_menu_options(game, &game->menu);
}

void render_menu_options(Game *game, Menu *menu)
{
    for (int i = 0; i < menu->option_count; i++)
    {
        MenuOption *option = &menu->options[i];
        render_menu_option(game, menu, option);
    }
}

void render_menu_option(Game *game, Menu *menu, MenuOption *option)
{
    SDL_RenderCopy(game->renderer, option->texture, &option->src_rect, &option->dst_rect);
}
