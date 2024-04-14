project('CSC145-RPG', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

includes = [
  'item'
]

game_src = [
  'BattleMenu.cpp',
  'DebugMenu.cpp',
  'Enemy.cpp',
  'enemyai.cpp',
  'Entity.cpp',
  'game.cpp',
  'inventory.cpp',
  'item/Equipment.cpp',
  'item/Item.cpp',
  'item/RegularItems.cpp',
  'Menu.cpp',
  'Player.cpp',
  'scene/Battle.cpp',
  'scene/Floor.cpp',
  'scene/Scene.cpp',
  'scene/Tower.cpp',
  'Status.cpp',
  'statustypes.cpp'
]

executable(
  'game',
  game_src,
  include_directories : includes,
  install : true
)