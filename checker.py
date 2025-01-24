import re
import os
def check_file(filename, silent=False):
    with open(filename, 'r') as file:
        source = file.read()

        pattern = \
r"""^\/\*$
^    Solution for: UVA [0-9]+ - .+[^ ]$
^    Problem Link: https:\/\/onlinejudge\.org\/external\/[0-9]+\/[0-9]+\.pdf$
^    Verdict: Accepted$
^    Submission ID: [0-9]+$
^\*\/$"""
    result = re.search(pattern, source, flags=re.MULTILINE)
    assert result
    if not silent : print(result.group(0))

if __name__ == '__main__':
    for root, dirs, files in os.walk('UVA_verified'):
        for file in files:
            check_file(os.path.join(root, file), silent=True)
            print("OK: ", os.path.join(root, file))            

