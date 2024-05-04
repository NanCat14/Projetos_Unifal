#include <iostream>
#include <fstream>
#include <string>

using namespace std;


 //==REGISTROS==//
 
const int TAM = 100;

typedef struct{
   string nome;
   string celular;
   string cidade;
   string email;
   bool valido;
}Pessoa;

int main() {

    system("chcp 65001");

    Pessoa agenda[TAM];
    int qtd = 0;
    string aux;
   
    ifstream arquivo("agenda.txt");     //Acesso e abertura do arquivo "agenda.txt"                                        

    if(!arquivo.is_open()){     //Teste para ver se o arquivo existe
        cout << "\nErro: arquivo nÃ£o encontrado!";
        return 1;
    }
    arquivo >> aux;     //O primeiro nome Ã© atribuido a uma variavel para checagem se ele Ã© igual a "fim"
   
    for(qtd = 0; aux != "fim" && qtd < TAM; qtd++){
        agenda[qtd].nome = aux;
        arquivo >> agenda[qtd].celular >> agenda[qtd].cidade >> agenda[qtd].email;
        agenda[qtd].valido = true;
        arquivo >> aux;
    }
    arquivo.close();    //Fechamendo do arquivo
   
    int num_pessoa = -1, aux2 = 0, opcao2 = 0, aux3 = 0, aux4 = 0;
    string nome = " ", opcao = " ";
   
    //Menu
    while(opcao != "0"){      //repetiÃ§Ã£o de menu
        system("cls");

        cout << "\n\n\t=====================MENU=====================" << endl;
        cout << "\tEscolha uma das opÃ§Ãµes abaixo: " << endl;
        cout << "\n\t1)Vizualizar a agenda completa." << endl;
        cout << "\t2)Alterar alguma informaÃ§Ã£o das Pessoas." << endl;
        cout << "\t3)Buscar alguma pessoa." << endl;
        cout << "\t4)Adicionar alguma pessoa." << endl;
        cout << "\t5)Excluir alguma pessoa." << endl;
        cout << "\t0)Sair." << endl;
        cout << "\n\t->Digite aqui: ";
        cin >> opcao;       //Entrada da opÃ§Ã£o escolhida

        system("cls");

        if(opcao == "0"){}
        else if(opcao == "1"){
            cout << "\n\t======================REGISTROS======================\n" << endl;
            cout << "\t   Nome   |   Celular  |   Cidade  |   Email\n" << endl;
            for(int i = 0; i < qtd; i++){
                if(agenda[i].valido){   //Se a variavel valido for false ele nÃ£o imprime a linha
                    cout << "\t" << agenda[i].nome << " | " <<  agenda[i].celular << " | " << agenda[i].cidade << " | " << agenda[i].email << endl;
                }
            }  
            cout << "\n\t===================================================" << endl;    
        }

        else if(opcao == "2"){ 
            
            aux2 = 0, aux3 = 0, nome = " ";

            cin.ignore();
            while(aux2 == 0){
                num_pessoa = -1;
                cout << "\t==============AlTERAR INFORMAÃ‡Ã•ES==============" << endl;
                cout << "\tEm quem vocÃª deseja fazer alteraÃ§Ãµes?" << endl;
                cout << "\t-Digite 'sair' caso nÃ£o queira editar." << endl;
                cout << "\t->Digite aqui: ";
                //cin.ignore();
                getline(cin, nome);    //Entrada do nome ou 'sair'

                ////////////////////////////////
                for (char &c : nome) {
                    if (c == ' ') {
                        c = '_';
                    }
                }

                cout << endl;
                if(nome != "sair"){
                    for(int i = 0; i < qtd; i++){
                        if(agenda[i].nome == nome && agenda[i].valido){  //se a pessoa for encontrada
                            num_pessoa = i;   //variavel num_pessoa recebe o indice que esta na agenda
                            i = qtd + 1;
                            aux2 = 1;
                        }
                    }
                    if(num_pessoa == -1){
                        cout << "\n\t*Pessoa nÃ£o encontrada, digite outro nome8*\n" << endl;
                        aux2 = 0;
                    }
                }
                else{
                    aux3 = 1;
                    aux2 = 1;
                } //Variavel para se caso a palavra "sair =" for lida
            }
        
            if(aux3 == 0){  //Aux2, checada acima
                cout << "\t-O que deseja mudar:" << endl;
                cout << "\t1)Nome - 2)Celular - 3)Cidade - 4)Email" << endl;
                cout << "\t->Digite aqui: ";
                cin >> opcao2;  //entrada da opÃ§Ã£o de ediÃ§Ã£o
                while(opcao2 > 3){
                    cout << "\t*OpÃ§Ã£o InvÃ¡lida! Digite novamente: ";
                    cin >> opcao2;
                    cin.ignore();
                }

                if(opcao2 == 1){
                    aux4 = 0;
                    while(aux4 == 0){  
                        cout << "\t-Digite o novo nome: ";
                        cin.ignore();
                        getline(cin, agenda[num_pessoa].nome);

                        //////////////////////////
                        for (char &c : agenda[num_pessoa].nome) {
                            if (c == ' ') {
                            c = '_';
                            }
                        }

                        for(int i = 0; i < qtd; i++){
                            if(agenda[num_pessoa].nome == agenda[i].nome && num_pessoa != i){
                               cout << "\t-------****-------\n\tNome jÃ¡ existente!\n\t-------****-------" << endl;
                               aux4 = 0;
                               i = qtd++; 
                            }
                            else{aux4 = 1;}
                        }

                    }
                }

                else if(opcao2 == 2){    //1-ediÃ§Ã£o de celular
                    cout << "\t-Digite o novo celular: ";
                    cin >> agenda[num_pessoa].celular;
                }
                else if(opcao2 == 3){   //2-EdiÃ§Ã£o de cidade
                    cout << "\t-Digite o nova Cidade: ";
                    cin.ignore();
                    getline(cin, agenda[num_pessoa].cidade);

                    //////////////////////////
                    for (char &c : agenda[num_pessoa].cidade) {
                        if (c == ' ') {
                           c = '_';
                        }
                    }
                }
                else if(opcao2 == 4){   //3-EdiÃ§Ã£o de email
                    cout << "\t-Digite o novo Email: ";
                    cin >> agenda[num_pessoa].email;
                }
                opcao = 1;
            }
            cout << "\t===============================================" << endl;
        }

        else if(opcao == "3"){ 
            aux2 = 0; //Variavel de condiÃ§Ã£o se encontrou ou nÃ£o
            cout << "\t===========BUSCAR ALGUÃ‰M===========" << endl;
            cout << "\t-Quem vocÃª deseja buscar: ";
            cin.ignore();
            getline(cin, nome);

                ///////////////////////////
            for (char &c : nome) {
                if (c == ' ') {
                    c = '_';
                }
            }  //Entrada do nome de quem serÃ¡ procurado


            for(int i = 0; i < qtd; i++){
                if(nome == agenda[i].nome && agenda[i].valido){
                    cout << "\n\t->Pessoa escohida: " << nome << "." << endl;
                    cout << "\t->Celular: " << agenda[i].celular << "." << endl;
                    cout << "\t->Cidade: " << agenda[i].cidade << "." << endl;
                    cout << "\t->Email: " << agenda[i].email << "." << endl;
                    aux2 = 1; //
                }
            }
            if(aux2 == 0){ //
                cout << "\n\t*Pessoa nÃ£o encontrada*" << endl;
            }
            cout << "\n\t===================================================" << endl;
        }

        else if(opcao == "4"){
            aux2 = qtd++; //Variavel recebe o nÃºmero da ultima linha para adiÃ§Ã£o
            cout << "\t==============ADICIONAR ALGUÃ‰M==============" << endl;  
            for(int i = 0; i < qtd; i++){
                if(agenda[i].valido == false){  //se alguma linha tiver false
                    aux2 = i;   //Variavel recebe o nÃºmero dessa linha para adiÃ§Ã£o
                    i = qtd+1;
                }
            }
            
            //AdiÃ§Ã£o de informaÃ§Ãµes
            aux4 = 0;
            cin.ignore();
            while(aux4 == 0){
                cout << "\t-Digite o nome: ";
                getline(cin, agenda[aux2].nome);

                ///////////////////////////
                for (char &c : agenda[aux2].nome) {
                    if (c == ' ') {
                        c = '_';
                    }
                }

                for(int i = 0; i < qtd; i++){
                    if(agenda[aux2].nome == agenda[i].nome && aux2 != i){
                        cout << "\t-------****-------\n\tNome jÃ¡ existente!\n\t-------****-------" << endl;
                        i = qtd++;
                        aux4 = 0;
                    }
                    else{
                        aux4 = 1;
                    }
                }
            }

            cout << "\t-Digite o Celular: ";
            cin >> agenda[aux2].celular;
            cout << "\t-Digite a Cidade: ";
            cin.ignore();
            getline(cin, agenda[aux2].cidade);

            ///////////////////////////////
            for (char &c : agenda[aux2].cidade) {
                if (c == ' ') {
                    c = '_';
                }
            }

            cout << "\t-Digite o Email: ";
            cin >> agenda[aux2].email;
            cout << endl;
            agenda[aux2].valido = true;
            cout << "\t=============================================" << endl;
        }
        
        else if(opcao == "5"){
          aux2 = 0; //Variavel de condiÃ§Ã£o se encontrou ou nÃ£o
            cout << "\t===========APAGAR ALGUÃ‰M===========" << endl;
            cout << "\t-Quem vocÃª quer apagar: ";
            cin.ignore();
            getline(cin, nome);    //Entrada de quem Ã© para ser apagado

            //////////////////////////////
            for (char &c : nome) {
                if (c == ' ') {
                    c = '_';
                }
            }

            for(int i = 0; i < qtd; i++){
                if(nome == agenda[i].nome && agenda[i].valido != false){
                    agenda[i].valido = false;   //valido recebe falso
                    cout << "\n\t-Pessoa apagada!" << endl;
                    aux2 = 1;   //
                }
            }
            if(aux2 == 0){  //
                cout << "\n\t*Pessoa nÃ£o encontrada*" << endl;
            }
            cout << "\n\t===================================================" << endl;
        };

        if(opcao != "0"){
            cout << "\n\t-VocÃª deseja sair?" << endl;
            cout << "\t0)Sair." << endl;
            cout << "\t1)Retornar ao menu principal" << endl;
            cout << "\t->Digite aqui: ";
            cin >> opcao;
        }
    }


    system("cls");
    cout << "\n\n\t==============VOCÃŠ-SAIU==============\n\n" << endl;


    //salvar no arquivo:
    ofstream arquivo_saida("agenda.txt");   //CriaÃ§Ã£o de uma variavel para a entrada das informaÃ§Ãµes digitadas
    for(int i = 0; i < qtd; i++){
        if(agenda[i].valido){
            arquivo_saida << agenda[i].nome<< " " << agenda[i].celular<< " " <<
            agenda[i].cidade << " " << agenda[i].email << endl;
        }
    }
    arquivo_saida << "fim"; //Ultima linha recebe "fim"


    arquivo_saida.close();  //Fechamento do arquivo.


    return 0;
}
