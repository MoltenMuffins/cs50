#!/usr/bin/env python3

"""Script for converting html in a given link to markdown
using the http://heckyesmarkdown.com/ API"""

import os
import io
import re
import argparse
import requests

API_URL = "http://heckyesmarkdown.com/go/"

def get_markdown(url):
    '''Returns the markdown response from http://heckyesmarkdown.com/go/'''
    try:
        markdown = requests.get(API_URL, params={"u": url}).text
    except Exception as ex:
        print("Unable to complete GET request:\n{}".format(ex))
        quit()
    return markdown

def clean_markdown(markdown):
    '''Removes unecessary links and lines from the markdown response'''
    raw_md = markdown.split('\n')
    url_dict = {}
    url_pattern = re.compile("(\[\d+\]): (\S*)")

    # Build url dict
    lines_to_skip = []
    start = False
    for idx, line in reversed(list(enumerate(raw_md, 1))):
        match = url_pattern.search(line)
        if match:
            num = match.group(1)
            url_dict[num] = match.group(2)
            lines_to_skip.append(idx)
            if num == '[1]':
                break

    cleaned_md_list = []
    link_pattern = re.compile("\[.*\](\[\d+\])")
    for i, line in enumerate(raw_md, 1):
        # Remove lines 2-78
        if i in range(2, 78 + 1):
            continue
        if i in lines_to_skip:
            continue
        # Replace links
        match = link_pattern.search(line)
        if match:
            line = line.replace(match.group(1),
                                '({})'.format(url_dict[match.group(1)]))
        cleaned_md_list.append(line)

    cleaned_md = '\n'.join(cleaned_md_list)
    return cleaned_md

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Converts a given website into a markdown page.')
    parser.add_argument('url', metavar='url', type=str,
                        help='url of webpage to convert to markdown')
    parser.add_argument('-f', '--filepath', dest='filepath', default=None,
                        help='Filepath for the generated markdown file.')
    args = parser.parse_args()

    if args.filepath:
        save_location = args.filepath
    else:
        save_location = os.path.abspath(os.path.join(os.path.dirname(os.path.realpath(__file__)),
                                                     "..", "converted.md"))

    markdown = get_markdown(args.url)
    markdown = clean_markdown(markdown)

    print("Saving converted markdown to: {}".format(save_location))
    with open(save_location, "w+") as f:
        f.write(markdown)
