# Claiming functions

If you're working the matching loop (see [CONTRIBUTING.md](CONTRIBUTING.md)),
claim before you sink time into a function, so two contributors don't
duplicate work on the same one.

This project now has its own board on the shared claims service - the manual
draft-PR convention that used to live here is retired:

- **Board:** https://tangos.dev/claims?project=pictochat
- **API:** `POST https://tangos.dev/api/claims/try-lock` with `"project":
  "pictochat"` in the body - the full contract (getting a key, renew, release)
  is at `GET https://tangos.dev/api/claims/instructions`.
- Modules are this repo's own names: `main`, `itcm`, `arm7`, `unk_autoload_0`.
- Locks expire on their own (24h TTL, renew while working), so a quiet session
  frees its range without anyone chasing a stale PR.

The site viewer, the tangOS Console and the batch tools all read this board
live, so a range you lock is dimmed and skipped everywhere within a minute.
Your PR still shows what you're working on, but it is no longer the claim.

## Before you claim anything

Run the free-match tools first - they might already cover it:

```
python tools/sync_ledger.py --apply    # catch your local ledger up to committed src/
python tools/templates.py --apply      # free template-tier matches (leaf shapes)
python tools/cross_match.py --other-repo ../sm64ds-decomp   # free cross-project matches
```

See [CONTRIBUTING.md](CONTRIBUTING.md) for the full matching loop and
[notes/tooling.md](notes/tooling.md) for what each tool does.

## Batches

If you're running `tools/templates.py --apply` or
`tools/permuter/batch.py --seeds ...` over a wide range, lock the module (or
the span you're sweeping) on the board first - these can land dozens of
functions at once, and someone else hand-matching in that same range finds
out through the board, not by watching PRs.
