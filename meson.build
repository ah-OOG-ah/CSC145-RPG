project('CSC145-RPG', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++20'])

includes = [
  'item'
#  'item/rooms',
]

game_src = [
  'DebugMenu.cpp',
  'Enemy.cpp',
  'enemyai.cpp',
  'Entity.cpp',
  'EquippedEntity.cpp',
  'game.cpp',
  'inventory.cpp',
  'item/Equipment.cpp',
  'item/Item.cpp',
  'item/RegularItems.cpp',
  'Menu.cpp',
  'Player.cpp',
  'scene/Battle.cpp',
  'scene/Floor.cpp',
  'scene/rooms/BattleRoom.cpp',
  'scene/rooms/EmptyRoom.cpp',
  'scene/rooms/Movement.cpp',
  'scene/rooms/Room.cpp',
  'scene/rooms/SafeRoom.cpp',
  'scene/rooms/ShopRoom.cpp',
  'scene/rooms/TreasureRoom.cpp',
  'scene/Scene.cpp',
  'scene/Tower.cpp',
  'ShopMenu.cpp',
  'Status.cpp',
  'statustypes.cpp'
]

executable(
  'game',
  game_src,
  include_directories : includes,
  install : true
)