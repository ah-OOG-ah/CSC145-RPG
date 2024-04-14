project('CSC145-RPG', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

includes = [
  'item'
]

game_src = [
  'Entity.cpp', 
  'Enemy.cpp',
  'enemyai.cpp',
  'game.cpp',
  'Menu.cpp',
  'DebugMenu.cpp',
  'Scene.cpp',
  'Battle.cpp',
  'BattleMenu.cpp',
  'Player.cpp',
  'RegularItems.cpp',
  'inventory.cpp',
  'Status.cpp',
  'statustypes.cpp',
  'item/Item.cpp',
  'Equipment.cpp'
]
executable(
  'game',
  game_src,
  include_directories : includes,
  install : true
)