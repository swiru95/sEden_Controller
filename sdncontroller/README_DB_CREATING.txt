POLISH

Polecenia do utworzenia bazy danych MySql 8.0>>
Tworzy DB o nazwie sdncontrollerdb, nastepnie przelacza sie na dzialania na tej DB, po czym tworzy tablice o nazwie flows nastepnie podaje dwa flowy dla umozliwienia komunikacji:
				
[h1(ip=1.0.0.1,mac=AA-...-A1)]<====>[|s1|]<====>[h2(ip=1.0.0.2,mac=AA-...-A2)]

Odpowiada to flow1.xml oraz topologi sieci mininet net1.py. W omnetpp.ini jest to jako Config TestDB bodajże.
UWAGA!
Najpierw nalezy zainstalowac lokalnie mysql-server z apt:
apt-get install mysql-server
UWAGA!
Aby omnetpp controller mogl uzywac mysql potrzeba zainstalowac i dolaczyc biblioteki:
apt-get install libmysqlcppconn-dev

Oto polecenia:

CREATE DATABASE IF NOT EXISTS sdncontrollerdb;
USE sdncontrollerdb;
CREATE TABLE IF NOT EXISTS flows(id int not null auto_increment, switchname varchar(16) not null, portin int not null, portout int not null, ipsrc varchar(15) not null, ipdst varchar(15) not null, macsrc varchar(17) not null, macdst varchar(17) not null);
--przyklad dodania dwoch flowow dla s1 dla sieci net1
INSERT INTO flows VALUES (1,'s1',1,2,'1.0.0.1','1.0.0.2','AA-AA-AA-AA-AA-A1','AA-AA-AA-AA-AA-A2');
INSERT INTO flows VALUES (1,'s1',2,1,'1.0.0.2','1.0.0.1','AA-AA-AA-AA-AA-A2','AA-AA-AA-AA-AA-A1');

ENGLISH

Creating database in MySql 8.0>>
Creating DB named sdncontrollerdb, then it uses DB, then adding table flows nextly adding flows which enable this kind of connection:
				
[h1(ip=1.0.0.1,mac=AA-...-A1)]<====>[|s1|]<====>[h2(ip=1.0.0.2,mac=AA-...-A2)]

Same connection parameters as in flow1.xml and mininet topology net1.py.In omnetpp.ini this is Config TestDB (or sth like this :)).
WARNING!
First install mysql from apt:
apt-get install mysql-server
WARNING!
To allow controller using mysql there is a need to install and include libraries:
apt-get install libmysqlcppconn-dev

This is short tutorial for DB settings:

CREATE DATABASE IF NOT EXISTS sdncontrollerdb;
USE sdncontrollerdb;
CREATE TABLE IF NOT EXISTS flows(id int not null auto_increment, switchname varchar(16) not null, portin int not null, portout int not null, ipsrc varchar(15) not null, ipdst varchar(15) not null, macsrc varchar(17) not null, macdst varchar(17) not null);
--examples of adding flows for S1 in net1 network
INSERT INTO flows VALUES (1,'s1',1,2,'1.0.0.1','1.0.0.2','AA-AA-AA-AA-AA-A1','AA-AA-AA-AA-AA-A2');
INSERT INTO flows VALUES (1,'s1',2,1,'1.0.0.2','1.0.0.1','AA-AA-AA-AA-AA-A2','AA-AA-AA-AA-AA-A1');
