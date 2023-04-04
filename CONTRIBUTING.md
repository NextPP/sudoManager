# Contributing
## Fork & Pull Request model for code contribution
---------------------------
### The instruction in brief
1.  Install [Git](https://git-scm.com/).
2.  Register at GitHub. Create your fork of sudoManager repository https://github.com/NextPP/sudoManager (see [fork-a-repo](https://help.github.com/articles/fork-a-repo) for details).
3.  Choose a task for yourself. It could be a [bugfix](https://github.com/NextPP/sudoManage/issues?q=is%3Aissue+is%3Aopen+label%3Abug) or some new code.
4.  Choose [main](https://github.com/NextPP/sudoManager/tree/main) as your base branch.
5.  Create a new branch (with a meaningful name) from the base branch you chose.
    -  For feature: feature/<issue_id>_<short_feature_description_snake_case>
    -  For bug: bug/<issue_id>_<short_bug_name_snake_case>
6.  Modify/add the code following [Google Coding style](https://google.github.io/styleguide/cppguide.html).
7.  When you are done, push your branch to your GitHub fork; then create a pull request from your branch to the base branch (see [using-pull-requests](https://help.github.com/articles/using-pull-requests) for details).


### Making a good pull request
Following these guidelines will increase the likelihood that your pull request is accepted:


1. Before pushing your PR to the repository, make sure that it builds perfectly fine on your local system.
2. Add enough information, like a meaningful title, the reason why you made the commit, and a link to the issue page if you opened one for this PR.
3. Focus your PR on one issue. Before submitting, make sure the diff contains no unrelated changes. If you want to cover more than one issue, submit your changes for each as separate pull requests.
4. If you have added new functionality, you should update or create tests for it in the test suite.
5. Try not to include "oops" commits, ones that just fix an error in the previous commit. If you have those, then before submitting, [squash](http://git-scm.com/book/en/Git-Tools-Rewriting-History#Squashing-Commits) those fixes directly into the commits where they belong.
6.  Make sure to choose the right base branch and follow the [Google Coding style](https://google.github.io/styleguide/cppguide.html) for your code.

## Issues
---------------------------
### Working on an issue
Issues marked with https://github.com/NextPP/sudoManager/labels/confirmed are
confirmed by the community and ready for work.

If you are a newcomer, you should pick issues that are https://github.com/NextPP/sudoManager/labels/good%20first%20issue
