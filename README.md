# Benchmarking tool for programming language comparison

## Usage (Docker)

<b>Note:</b> Docker must be installed on your system

### Execution

- Run all programs `./run.sh`
- Run certain language/languages only `./run.sh <js|swift|kotlin|java|dart|go|c|cpp>` separated with comma

### Adding new languages

- Use this template for a Dockerfile (<b>In different directory, do not change Dockerfile for this project!!!</b>) to install all required packages on image:

```Dockerfile
FROM picroc/lang_driver:0.5

# RUN ALL INSTALLATION COMMANDS HERE
```

- Build and tag your new image:
  `docker build -t <yourDockerHubRepo>/<imageName>:<imageVersion> .`
- Push built image to DockerHub:
  `docker push <yourDockerHubRepo>/<imageName>:<imageVersion>`
- Update image in project's Dockerfile (change `FROM <image>` statement at the beggining of the file)
- As a temporary solution, you may add installation steps directly to the project's Dockerfile, but it is recommended to use published images
