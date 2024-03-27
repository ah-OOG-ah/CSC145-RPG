project('CSC145-RPG', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

inc_dirs = [ 'Menu' ]

game_src = [ 
  'Entity.cpp', 
  'game.cpp',
  'Menu/Menu.cpp',
  'Menu/DebugMenu.cpp',
  'Scene.cpp',
  'Battle.cpp',
  'Menu/BattleMenu.cpp',
  'Player.cpp',
  'RegularItems.cpp',
  'inventory.cpp',
  'Status.cpp',
  'item.cpp',
  'Equipment.cpp',
  'Menu/StartMenu.cpp',
  'Floor.cpp',
  'Tower.cpp'
]   
executable(
  'game',
  game_src,
  include_directories: inc_dirs,
  install : true
)