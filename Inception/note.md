# コンテナとは
コンテナとはマシン上でサンドボックス化したプロセスであり、ホストマシン上にある他全てのプロセスから隔離されています
隔離にはカーネル名前空間とcgruopの活用であり、長らくLinuxに存在する機能です

1. イメージの実行可能な実体。Docker APIやCLIを使い、コンテナの作成、開始、停止、移動、削除ができます
2. ローカルマシーン上や仮想マシーン上で実行できるのに加えクラウドにデプロイもできます
3. 可搬性があります
4. コンテナはお互いに隔離され、実行にはそれぞれが自身のソフトウェア、バイナリ、設定を使います

# コンテナイメージとは？
コンテナを実行したら、コンテナは隔離されたファイルシステムを使います
この特別なファイルシステムはコンテナイメージによって提供されます

# Dockerファイル
Dockerfileはテキストファイルであり、イメージを作り上げるのために実行するコマンドライン命令を書く

## CMD
コンテナの起動後に指定された命令を実行します
ENTRYPOINTが定義されているならこの命令はENTRYPOINTの引数として解釈されます


## ENTRYPOINT
コンテナの起動時に実行される実行可能ファイルを設定します
任意のCMD命令や、イメージの後に続くdocker runの引数は指定した実行可能ファイルへのパラメータとして渡されます

## docker build

Docker buildコマンドはDockerfileとコンテキストからイメージをbuildします
```
$ docker build [オプション] パス | URL | -
```

## docker run
コンテナを起動するには、 docker run コマンドを使い、先ほど作成したイメージ名を指定します
```
$ docker run [オプション] イメージ[:タグ|@ダイジェスト値] [コマンド] [引数...]

$ docker run -d -p 80:80 my_image service nginx start
```

# Composeファイル
ComposeファイルとはDockerアプリケーション用のサービス、ネットワーク、ボリュームを定義したYAMLファイルです

# Dockerデーモン
DockerデーモンはDocker APIリクエストを受けつけ、イメージ、コンテナ、ネットワーク、ボリュームといったDockerオブジェクトの管理をします


# 要件
* 各Docker イメージは、対応するサービスと同じ名前を持つ必要があります。
* 各サービスは専用コンテナで実行する必要があります。
* パフォーマンスの問題では、コンテナはAlpineまたはDebianの最後から2番目の安定バージョンから構築する必要があります。
* 選択はあなた次第です。
* また、サービスごとに1つずつ、独自のDockerfilesを作成する必要があります。
* Dockerfiles は、Makefile によって docker-compose.yml で呼び出される必要があります。
* これは、プロジェクトのDockerイメージを自分で構築する必要があることを意味します。
* 次に、既製のDockerイメージを引き出し、DockerHub（Alpine/Debianはこのルールから除外されます）などのサービスを使用することが禁止されています。

## nginx
* Your NGINX container must be the only entrypoint into your
infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3
protocol.

- apt-get install
    - a

## WP & PHP
* A Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx.
* A volume that contains your WordPress database.
* A second volume that contains your WordPress website files.
* In your WordPress database, there must be two users, one of them being the ad- ministrator. The administrator’s username can’t contain admin/Admin or admin- istrator/Administrator (e.g., admin, administrator, Administrator, admin-123, and so forth).

- apt-get install
    - a

## mariaDB
* A Docker container that contains MariaDB only without nginx.

- apt-get install
    - a


## env
The latest tag is prohibited.
No password must be present in your Dockerfiles.
It is mandatory to use environment variables.
Also, it is strongly recommended to use a .env file to store
environment variables.  The .env file should be located at the root
of the srcs directory.
Your NGINX container must be the only entrypoint into your
infrastructure via the port 443 only, using the TLSv1.2 or TLSv1.3
protocol.

## tips
* コンテナIDを取得したい時
```
docker ps -lq
```

* 停止したコンテナのクリーンアップ
```
docker rm -v $(docker ps -aq -f status=exited)
```

