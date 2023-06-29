#!/usr/bin/env python3
import os
import time
import json


def get_dpow_commit_hashes(refresh: bool=True) -> dict:
    data = parse_dpow_commit_hashes()
    with open("../doc/daemon_versions.json", "w") as f:
        json.dump(data, f, indent=4)
    return data

def parse_dpow_commit_hashes() -> dict:
    data = {}
    with open("../README.md", "r") as f:
        for line in f.readlines():
            split_line = line.split()
            if len(split_line) > 0:
                last_word = split_line[-1].lower()
                if last_word in ["dpow-3p", "dpow-mainnet"]:
                    parts = [i.strip() for i in line.split("|")]
                    coin = parts[0]
                    commit = parts[2].replace("[", "").split("]")[0]
                    print(f"{coin}: {commit}")
                    data[coin] = commit
    return data

if __name__ == "__main__":
    get_dpow_commit_hashes()

