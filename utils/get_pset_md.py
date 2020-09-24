#!/usr/bin/env python3

"""Script for converting html in a given link to markdown
using the http://heckyesmarkdown.com/ API"""

import os
import argparse
import requests

API_URL = "http://heckyesmarkdown.com/go/"

def get_markdown(url):
    try:
        markdown = requests.get(API_URL, params={"u": url}).text
    except Exception as ex:
        print("Unable to complete GET request:\n{}".format(ex))
        quit()
    return markdown

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

    print("Saving converted markdown to: {}".format(save_location))
    with open(save_location, "w+") as f:
        f.write(markdown)
