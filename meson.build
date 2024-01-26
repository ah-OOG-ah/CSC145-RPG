project('CSC145-RPG', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++23', 'prefer_static=true', 'default_library=static'])

game_src = [ 
  'Entity.cpp', 
  'game.cpp',
  'Menu.cpp',
  'MenuEntry.cpp'
]   
executable(
  'game',
  game_src,
  install : true
)