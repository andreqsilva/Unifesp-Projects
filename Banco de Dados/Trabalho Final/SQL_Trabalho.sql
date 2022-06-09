/* CREATE DATABASE TheOffice; */

/*
CREATE TABLE Cidade (
	siglaCidade varchar(3),
    nomeCidade varchar(20),
    nomeEstado varchar(20),
    PRIMARY KEY(siglaCidade)
);

CREATE TABLE Predio (
	nroPredio integer,
    cepRua varchar(15),
    siglaCidade varchar(3),
    PRIMARY KEY(nroPredio),
    FOREIGN KEY(siglaCidade) REFERENCES Cidade(siglaCidade)
);

CREATE TABLE Matriz (
	codPresidente integer,
    nroPredio integer,
    nomePresidente varchar(20),
    PRIMARY KEY(codPresidente),
    FOREIGN KEY(nroPredio) REFERENCES Predio(nroPredio)
);

CREATE TABLE Filial (
	codFilial integer,
    nroEscritorio integer,
    andar integer,
    nroPredio integer,
    PRIMARY KEY(codFilial),
    FOREIGN KEY(nroPredio) REFERENCES Predio(nroPredio)
);

CREATE TABLE Empregado (
	idEmpregado integer,
    codFilial integer,
    nomeEmpregado varchar(20),
    cpfEmpregado integer,
    sexoEmpregado char,
    cargo varchar(20),
    PRIMARY KEY(idEmpregado),
    FOREIGN KEY(codFilial) REFERENCES Filial(codFilial)
);

CREATE TABLE Vendedor (
	idVendedor integer,
    idEmpregado integer,
    PRIMARY KEY(idVendedor),
    FOREIGN KEY(idEmpregado) REFERENCES Empregado(idEmpregado)
);

CREATE TABLE Mercadoria (
	codMercadoria integer,
    tipoMercadoria varchar(10),
    quantidadeMercadoria integer,
    PRIMARY KEY(codMercadoria)
);

CREATE TABLE Venda (
	idVenda integer,
    codMercadoria integer,
    idVendedor integer,
    dataVenta date,
    precoVenda float,
    PRIMARY KEY(idVenda),
    FOREIGN KEY(codMercadoria) REFERENCES Mercadoria(codMercadoria),
    FOREIGN KEY(idVendedor) REFERENCES Vendedor(idVendedor)
);

CREATE TABLE Cliente (
	idCliente integer,
    nomeCliente varchar(20),
    cep varchar(15),
    nroCasa integer,
	idVenda integer,
    PRIMARY KEY(idCliente),
    FOREIGN KEY(idVenda) REFERENCES Venda(idVenda)
);

CREATE TABLE Rota (
	codRota integer,
    diaSemana date,
    horario time,
    idCliente integer,
    PRIMARY KEY(codRota),
    FOREIGN KEY(idCliente) REFERENCES Cliente(idCliente)
);

CREATE TABLE Motorista (
	idMotorista integer,
    idEmpregado integer,
    codRota integer,
    PRIMARY KEY(idMotorista),
    FOREIGN KEY(idEmpregado) REFERENCES Empregado(idEmpregado),
    FOREIGN KEY(codRota) REFERENCES Rota(codRota)
);
**************************************/

/*
INSERT INTO Cidade 
VALUES  ('NY', 'New York', 'New York'),
		('AK', 'Akron', 'Ohio'),
		('AL', 'Albany', 'New York'),
        ('BG', 'Binghamton ', 'New York'),
        ('BU', 'Buffalo', 'New York'),
        ('CA', 'Camden', 'New Jersey'),
        ('NA', 'Nashua', 'New Hampshire'),
        ('PI', 'Pittsfield', 'Massachusetts'),
        ('RC', 'Rochester', 'New Hampshire'),
        ('SC', 'Scranton', 'Pennsylvania');

INSERT INTO Predio (nroPredio, siglaCidade, cepRua)
VALUES 	(125, 'NY', '15345-11'),
		(302, 'NY', '15140-17'),
        (100, 'BU', '24152-21'),
        (45, 'CA', '31574-74'),
        (27, 'CA', '31100-44'),
        (55, 'PI', '77123-57'),
        (214, 'RC', '91233-32'),
        (16, 'NA', '52985-13'),
        (140, 'NA', '52525-31'),
        (10, 'SC', '13927-19'),
        (413, 'AK', '01542-15'),
		(200, 'AL', '40015-22'),
        (512, 'BG', '77881-02');

INSERT INTO Matriz
VALUES (01, 'NY', 125, 'David Wallace')

INSERT INTO Filial
VALUES  (1, 12, 5, 302),
		(2, 30, 8, 100),
        (3, 11, 14, 45),
		(4, 15, 9, 55),
        (5, 20, 12, 214),
        (6, 100, 10, 16),
        (7, 200, 5, 10),
        (8, 10, 15, 413),
        (9, 145, 21, 200),
        (10, 71, 25, 512);
*/


