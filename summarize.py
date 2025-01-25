import re
import os
import json
import sys

def parse_header(filename):
    with open(filename, "r") as file:
        source = file.read()

    pattern = r"""^\/\*$
    Solution for: UVA (?P<prob_no>\d+) - (?P<prob_title>.*[^\s])$
    Problem Link: (?P<prob_link>https:\/\/onlinejudge\.org\/external\/(?P<link_vol>\d+)\/(?P<link_prob_no>\d+)\.pdf$)
    Verdict: Accepted$
    Submission ID: (?P<sub_id>\d+)$(
    Tags: (?P<tags>.*[^\s])$)?
\*\/$"""
    header = re.match(pattern, source, flags=re.MULTILINE)
    assert header

    header = header.groupdict()
    assert header["link_prob_no"] == header["prob_no"]
    assert header["link_vol"] == header["prob_no"][:-2]
    assert os.path.basename(filename) == "UVA" + header["prob_no"] + ".cpp"
    assert re.search(r"Volume_(\d+)", filename).group(1) == header["link_vol"]
    return header


if __name__ == "__main__":
    verbose = False
    summary_file = "summary.json"
    headers = []
    for root, dirs, files in os.walk("UVA_verified"):
        for file in files:
            try:
                header = parse_header(os.path.join(root, file))
                headers.append(header)
                if verbose:
                    print("OK: ", os.path.join(root, file), file=sys.stderr)
                    print(json.dumps(header, indent=2), file=sys.stderr)
            except:
                print("FAIL: ", os.path.join(root, file), file=sys.stderr)
                exit(1)
    headers = sorted(headers, key=lambda header: int(header["prob_no"]))

    print(f"OK: data saved in {summary_file}", file=sys.stderr)
    with open(summary_file, "w") as file:
        json.dump(headers, file, indent=2, sort_keys=True)
    exit(0)
