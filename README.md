# 3D Game - MiniLibX

Cub3D is a challenging project centered around constructing a raycasting game engine entirely from scratch, utilizing the C programming language. The primary objective of this endeavor is to render a 3D world within a 2D map, simulating navigation through intricate mazes. Your task is to develop a robust game engine capable of rendering walls, sprites, and managing player movement within a basic 3D setting.

|    Project Name    |                                                                       cub3d                                                                       |
| :----------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------: |
|    Description     |                                             A 3D game created from scratch written in C using raycasting                                            |
|    Technologies    | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries |     open(), close(), read(), write(), printf(), malloc(), free(), perror(), strerror(), exit(), All functions from math.h, All functions of the MinilibX      |

## Installation

```bash
  gcl https://github.com/trobert42/cub3d.git
  cd cub3d
  make bonus
  ./cub3D_bonus maps/bonus.cub
```
You can change the map by editing the files finishing by .cub inside the map directory. Keep in mind that it follows some rules so if it's not correct, it will display some errors about it.

NB:
If you use WSL and have some trouble with "can't find a suitable x11 include directory", i suggest to follow those steps here: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#getting-a-screen-on-windows-10-wsl2

## Commands

`A` : turn the camera to the left

`D` : turn the camera to the right

`W` : move forward

`S` : move back

`E` : to appear/disappear the wood box (you have to be close and right in front of the block)

<sub><sub>keyboard is in qwerty, yes we code with a keyboard in EN</sub></sub>

## 💬
The mathematical formulas were hard to understand and to implement correctly in the code but we were satisfied when the rendering was clean. I remember how i was happy when i just rendered a single block of blue in the screen, haha! 

Thank you Luna, it was interesting to work with you and we had so much fun !

## Screenshots

NB: With my teammate, we found it funny to see the link's texture so we kept it like that. It was her sprites for another project.

![](https://github.com/trobert42/cub3d/blob/main/cub3d_bonus_clip.gif)
