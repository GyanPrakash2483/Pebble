# Contributing to uefi-headers

Thanks for your interest in contributing! This project is small, so the process is kept simple.

## Ways to Help

- **Documentation**: improve comments, the README, or add usage examples.
- **Report issues**: found something that doesn't match the UEFI specification? Please let us know.
- **Fix mistakes and bugs**: wrong type sizes, incorrect GUIDs, typos, missing definitions, or anything else that looks off.

## Reporting Issues

Open an issue on the [issue tracker](https://github.com/GyanPrakash2483/uefi-headers/issues) and include:

- What is wrong or different from the specification.
- The file and line (or definition name) where it happens.
- The relevant section of the UEFI specification, with its version, if possible.

## Submitting Changes

1. **Fork** the repository to your own GitHub account.
2. **Clone** your fork and create a new branch for your change:
   ```sh
   git clone https://github.com/<your-username>/uefi-headers.git
   cd uefi-headers
   git checkout -b my-fix
   ```
3. **Make your changes.** Keep them focused: one fix or improvement per PR.
4. **Commit** with a clear message describing what you changed and why.
5. **Push** the branch to your fork:
   ```sh
   git push origin my-fix
   ```
6. **Open a Pull Request** against the `main` branch of this repository.

In your PR description, explain the change and link the related issue or specification section if there is one.

## Guidelines

- Follow the existing code style and naming used in the headers.
- Make sure definitions match the UEFI specification.
- Check that the headers still compile after your change.

Thank you for helping make uefi-headers better!