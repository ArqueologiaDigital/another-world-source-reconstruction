# CAPSULE (amiga) — two trampolines with unique named targets

The other two (`JUMP_TO_LABEL_8C88_AT_8BDB`, `..._AT_8C68`) share a target and
additionally carry an `_AT_<addr>` tail; both problems need the caller, not the
callee, so they are left alone.

| routine | new name | confidence |
|---|---|---|
| JUMP_TO_LABEL_34D8 | JUMP_TO_CAPSULE_ACTOR_TICK_FACING_LEFT_LOOP | high |
| JUMP_TO_LABEL_34F8 | JUMP_TO_CAPSULE_ACTOR_TICK_FACING_RIGHT_LOOP | high |
