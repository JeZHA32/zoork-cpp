# ZOOrk — Text Adventure Engine in C++17

A modular text-adventure game engine built in C++17 as part of my Master of IT capstone in *Professional Software Development* at La Trobe University (graded 83 / HD).

## What it does
- 11 interconnected rooms with 11 NPCs and an inventory/item system
- Player commands: `look`, `take`, `drop`, `talk`, `go [direction]`
- Walkthrough completion possible via the included winning command sequence

## What I practiced
- **OOP & SOLID principles**: separation of engine, world, and command layers
- **Three classical design patterns**:
  - **Singleton** for the Player object
  - **Command** for player actions (look / take / drop / talk / go)
  - **Null Object** for safe handling of invalid rooms and passages
- **Memory model**: `std::shared_ptr` ownership, no raw `new`/`delete`
- **Modular architecture**: each class in its own `.h` / `.cpp` translation unit

## Build
```bash
mkdir build && cd build
cmake ..
make
./zoork
```

## File structure
- `GameObject`, `Character`, `Player` — base hierarchy
- `Location`, `Room`, `Passage`, `NullRoom`, `NullPassage` — world model
- `Command`, `RoomDefaultEnterCommand`, `PassageDefaultEnterCommand`, `NullCommand` — command pattern
- `ZOOrkEngine` — main game loop and command parser
