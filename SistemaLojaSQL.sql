CREATE DATABASE LOJA;
USE LOJA;

CREATE TABLE TBUSUARIO(
      USACODIGO INT AUTO_INCREMENT PRIMARY KEY,
      USAUSUARIO VARCHAR (50) NOT NULL,
      USASENHA VARCHAR (32) NOT NULL,
      USATIPO INT NOT NULL
);

CREATE TABLE TBPRODUTO (
      PROCODIGO INT AUTO_INCREMENT PRIMARY KEY,
      PRODESCRICAO VARCHAR (50) NOT NULL,
      PROPRECO NUMERIC(9,2) DEFAULT 0
);

CREATE TABLE TBDOCUMENTO (
      DOCCODIGO INT PRIMARY KEY,
      DOCTOTAL NUMERIC(9,2) DEFAULT 0,
      DOCSITUACAO INT DEFAULT 0
);


CREATE TABLE TBITEM (
      DOCCODIGO INT NOT NULL,
      PROCODIGO INT NOT NULL,
      CONSTRAINT FK_TBDOCUMENTO  FOREIGN KEY (DOCCODIGO) REFERENCES TBDOCUMENTO(DOCCODIGO),      
      CONSTRAINT FK_TBPRODUTO FOREIGN KEY (PROCODIGO) REFERENCES TBPRODUTO(PROCODIGO)    
);

INSERT INTO TBUSUARIO
       (USAUSUARIO, USASENHA, USATIPO)
VALUES ('adm',MD5('123'), 0),
       ('vend',MD5('456'), 1);              