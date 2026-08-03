# External NDS Decompilation Reference Library (`extern/`)

This directory is configured to hold external Nintendo DS decompilation repositories as git submodules.

To keep clones fast, lightweight, and bandwidth-friendly, **none of these external repositories are checked out by default**.

---

## Managing External Repositories

You can manage reference repositories using `tools/manage_extern.py`:

```bash
# List all registered external NDS decompilation repositories and their status
python tools/manage_extern.py list

# Clone/checkout a specific reference repository (e.g. sm64ds-decomp)
python tools/manage_extern.py clone sm64ds-decomp

# Clone/checkout all registered external repositories
python tools/manage_extern.py clone all

# De-initialize a repository (remove checked out files without removing configuration)
python tools/manage_extern.py deinit sm64ds-decomp
```

---

## Registered NDS Decomp Repositories

Every URL below was verified to actually exist (`gh api repos/<owner>/<repo>`) before being
registered - a prior version of this file listed several plausible-sounding but nonexistent
repos (`Mariokartds-decomp/mariokartds`, `nsmb-decomp/nsmb-decomp`, `zelda-ph-decomp/zelda-ph-decomp`,
`metroid-prime-hunters/mph-decomp`, `acww-decomp/acww-decomp` - all 404). If you add a new entry,
verify it the same way first.

- `sm64ds-decomp`: *Super Mario 64 DS* (`https://github.com/tangosdev/sm64ds-decomp`) - same
  mwccarm/CodeWarrior ARM toolchain family as this project; largest, most mature codegen-lever
  catalogue of any project on this list (`notes/mwccarm-codegen.md`).
- `pokeheartgold`: *Pokémon HeartGold / SoulSilver* (`https://github.com/pret/pokeheartgold`)
- `pokediamond`: *Pokémon Diamond / Pearl* (`https://github.com/pret/pokediamond`)
- `pokeplatinum`: *Pokémon Platinum* (`https://github.com/pret/pokeplatinum`) - rich `// ... to
  match` idiom comments throughout matched source.
- `pmd-sky`: *Pokémon Mystery Dungeon: Explorers of Sky* (`https://github.com/pret/pmd-sky`)
- `twewy`: *The World Ends With You* (`https://github.com/Yotona/twewy`) - real ARM/NDS mwccarm
  decomp; source of the volatile-parameter arg-spill lever used on this project's
  `FUN_022d5a64`.
- `fe11-us`: *Fire Emblem: New Mystery of the Emblem (US)* (`https://github.com/Eebit/fe11-us`)
- `atc`: *Air Traffic Chaos* (`https://github.com/sasja-san/atc`)
- `khdays-decomp`: *Kingdom Hearts 358/2 Days* (`https://github.com/Yokimitsuro/khdays-decomp`)

---

## Pattern Scraping & Cross-Referencing

Once one or more external repos are cloned (or local reference folders are added), run the cross-referencing scraper:

```bash
# Scrape cloned extern repos and build the pattern index
python tools/cross_reference.py scrape

# Search for assembly patterns or SDK symbols
python tools/cross_reference.py search --name OS_
python tools/cross_reference.py search --asm "mrc p15"

# Automatically cross-match unverified local functions against the extern pattern library
python tools/cross_reference.py cross-match
```
