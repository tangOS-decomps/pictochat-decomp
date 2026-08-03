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

- `sm64ds-decomp`: *Super Mario 64 DS* (`https://github.com/n64decomp/sm64ds`)
- `pokeheartgold`: *Pokémon HeartGold / SoulSilver* (`https://github.com/pret/pokeheartgold`)
- `pokediamond`: *Pokémon Diamond / Pearl* (`https://github.com/pret/pokediamond`)
- `mariokartds`: *Mario Kart DS* (`https://github.com/Mariokartds-decomp/mariokartds`)
- `nsmb-decomp`: *New Super Mario Bros.* (`https://github.com/nsmb-decomp/nsmb-decomp`)
- `zelda-ph-decomp`: *The Legend of Zelda: Phantom Hourglass* (`https://github.com/zelda-ph-decomp/zelda-ph-decomp`)
- `mph-decomp`: *Metroid Prime Hunters* (`https://github.com/metroid-prime-hunters/mph-decomp`)
- `acww-decomp`: *Animal Crossing: Wild World* (`https://github.com/acww-decomp/acww-decomp`)

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
