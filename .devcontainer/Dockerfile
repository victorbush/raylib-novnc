FROM mcr.microsoft.com/devcontainers/cpp

# Install clangd-19 and set it as the default
USER root
RUN apt-get update \
    && apt-get install -y --no-install-recommends clangd-19 \
    && update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-19 100 \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Back to the vscode user
USER vscode
