# irpra-app
Túnel de diretórios para acesso rápido

## Como compilar
Compile o código com gcc normalmente: `gcc main.c -o <nome_do_executável>`  
> NOTA: o nome do executável tem que ser o mesmo dentro dos arquivos .bat e .ps1, como padrão está: `ìrpra_handler.exe`.

## Como usar
O usuário deve usar executando os scripts de .bat ou .ps1 com o argumento do apelido de seu diretório: `irpra projetos-c`
então o programa localizará seu terminal no caminho do apelido `projeto-c`.  
É também possível usar a flag `-e` para simbolizar que o diretório deve ser aberto também no explorador de arquivos: `irpra -e projetos-c`

## Como adicionar apelidos
Ao executar pela primeira vez, o programa criará um arquivo de texto `irpra_directs.txt` em sua pasta raiz.  
O usuário deve alterá-la de forma que cada linha contenha o seguinte: `<apelido>;<caminho>;`.  
Exemplo: `projetos-c;D:\programacao\projetos\c;`

## Como colocar no PATH do sistema
É possível colocar o aplicativo no PATH para que os scripts sejam acessíveis de qualquer diretório em que o CMD esteja.  
É preciso editar as variáveis de ambiente do sistema, e depois editar o PATH, adicionando o local de arquivo que ficará o script.  
> NOTA: é necessário que no caminho do path estejam os arquivos `irpra_handler.exe`, `irpra.ps1` e `irpra.bat`