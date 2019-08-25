### Run in docker

Simple and fast setup of BASIC on Docker is also available. Firstly, install dependencies:
 - [Docker](https://docs.docker.com)
 - [Docker-compose](https://github.com/docker/compose)
 - [Docker-volumes](https://github.com/cpuguy83/docker-volumes)

Build basic image

```
git clone https://github.com/BASICIO/basic.git --recursive
cd basic
cp genesis.json Docker 
docker build -t basicio/basic -f Docker/Dockerfile .
```

Start docker

```
sudo rm -rf /data/store/basic # options 
sudo mkdir -p /data/store/basic
docker-compose -f Docker/docker-compose.yml up
```

Get chain info

```
curl http://127.0.0.1:8888/v1/chain/get_info
```

Run example contracts

You can run the `basicc` commands via `docker exec` command. For example:
```
cd /data/store/basic/contracts/exchange
docker exec docker_basic_1 basicc contract exchange contracts/exchange/exchange.wast contracts/exchange/exchange.abi

```

Done
