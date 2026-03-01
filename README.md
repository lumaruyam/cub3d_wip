*This project has been created as part of the 42 curriculum by lulmaruy, niconguy.*

## Description

cub3D is a first-person 3D maze explorer built using raycasting techniques, inspired by the original Wolfenstein 3D engine. The goal is to render a realistic 3D view of a maze from a first-person perspective using the MinilibX graphics library.

## Instructions

### Compilation
```bash
make
```

### Usage
The command below automatically opens the window and you are able to navigate with following keys:
```bash
./cub3D map/example.cub
````

Change the map/example.cub to path/to/map.cub

### Controls
| Key | Action |
|-----|--------|
| W | Move forward |
| S | Move backward |
| A | Strafe left |
| D | Strafe right |
| ← | Rotate left |
| → | Rotate right |
| ESC | Quit |


## Resources
- [Texture resources](https://opengameart.org/textures/) : Wall texture resources
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) : Primary reference for the DDA raycasting algorithm
- [MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx) : MLX function reference

**AI Usage**: LLM was used to assist with understanding the subject and mathmatics concepts and formatting the README.md
