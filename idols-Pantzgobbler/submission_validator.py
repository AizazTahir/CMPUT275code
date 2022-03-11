# source logan/grading_tools
# Copyright 2020 Logan Gilmour
# Modified by Xinlei Chen, Paul Lu


import os
import shutil
from tempfile import gettempdir
from random import randint
from contextlib import contextmanager
import argparse

conf = {
    "submission_name": "./soln/",
    "specified_files": ["idols.cpp", "README"],
    "assignment_version": "Weekly Exercise #2",
}

class ValidationException(Exception):
    pass


def get_contents(path):
    names = []
    for root, subFolder, files in os.walk(path):
        # names = []
        for name in files:
            subdir = os.path.relpath(root, path)
            if subdir != ".":
                names.append(os.path.join(subdir, name))
            else:
                names.append(name)
    return names


def validate_contents(archive_filename, extracted_dir, specified_files):
    isError = False
    found_files = get_contents(extracted_dir)

    for i in specified_files:
        if i in found_files:
            continue
        else:
            isError = True
            print("{} should contain '{}', but it is missing.".format(archive_filename,i))

    if not isError:
        print("Found required files.")
    else:
        print("Some file(s) missing.")
        raise ValidationException



def validate_submission():
    print("=== CMPUT 275 {} Validator ===".format(conf["assignment_version"]))

    try:
            validate_contents(conf["submission_name"],conf["submission_name"],conf["specified_files"])
            print("File structure is correct.")

            print("\nVALIDATION SUCCEEDED.")
            print("\nDISCLAIMER: This does not mean that your submission is correct "
                  "- just that it appears to be structured correctly.")

    except ValidationException as e:
        print("\nVALIDATION FAILED")
        print(e)
        print("Please fix this and try validating again.")
    except Exception as e:
        print("\nVALIDATION FAILED")
        print("Exception occurred: {}".format(e))
        print("Stopping validation. Please fix this and try again.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
                    description='''This script helps you to verify that your submission structure is correct for {}.
Usage:
  1. Place this file in the same directory as your clone of the git repository.
  2. Run the program using:
        python3 submission_validator.py
  3. The verification results will be shown.
      - If you see "VALIDATION SUCCEEDED", your submission appears to be
        structured correctly.
      - Otherwise, if you see "VALIDATION FAILED", you should examine the
        error message, fix the problem, and try again.
                                '''.format(conf["assignment_version"], conf["submission_name"], conf["submission_name"], conf["submission_name"]),
                                formatter_class = argparse.RawTextHelpFormatter

                    )
    args = parser.parse_args()

    validate_submission()

