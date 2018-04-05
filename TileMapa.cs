using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;
using UnityEngine.SceneManagement;

public class TileMapa : MonoBehaviour{

    //Nosso jogador.
    public GameObject player;

    //tipoTile ira retornar o tipo do nosso tile.
    public TipoTile[] tipoTile;

    //Tiles sera uma matriz de inteiros.
    int[,] tiles;

    //O grafo sera uma matriz de nodos que se ligaram entre si.
    Nodo[,] grafo;

    //Tamanho do nosso mapa/grafo.
    public int mapSizeX;
    public int mapSizeY;


    void Start(){

        //Associando o mapa do player, a toda função TileMapa.
        player.GetComponent<Objeto>().mapa = this;
        gerarMapa();
        gerarGrafo();
        instanciarMapa();

    }



    public void restartLevel(){
        
        //Reeniciar nivel.
        SceneManager.LoadScene("Scene1");   
}


    void gerarMapa(){

        //Alocação do mapa.
        tiles = new int[mapSizeX, mapSizeY];

        //Função que gera um numero aleatorio.
        System.Random aleatorio = new System.Random();

        //Inicializando o mapa randomico.
        for (int x = 0; x < mapSizeX; x++){
            for (int y = 0; y < mapSizeY; y++){

                //num tem valor minimo como 0, e maximo como 4.
                int num = aleatorio.Next(0, 4);
                //Nosso vetor "escolha" fará com que os numeros fiquem entre 0 e 3.
                int[] escolha = new int[4] { 0, 1, 2, 3};
                //Nossa matriz tiles em cada posição x,y irá receber um numero aleatorio.
                tiles[x, y] = escolha[num];

            }
        }

        //Posiçao inicial do player sempre sera tile mato.
        tiles[0, 0] = 1;
    }





    //Retorna o custo de cada tipo de tile.
    float custoTile(int x, int y){

        //tipoTile ira retornar o tipo do nosso tile na posição [x,y], e jogar para o "tt".
        TipoTile tt = tipoTile[tiles[x, y]];
        //retornando o peso/custo do tile.
        return tt.custoMov;
    }




    //criando uma lista de nodos que contem os grafos.
    void gerarGrafo(){

        //inicializando o vetor.
        grafo = new Nodo[mapSizeX, mapSizeY];

        for (int x = 0; x < mapSizeX; x++){
            for (int y = 0; y < mapSizeY; y++){

                //Instancio nosso grafo.
                grafo[x, y] = new Nodo();
                //Cada posição [x,y] do grafo será associada a mesma posição em nossa matriz.
                grafo[x, y].x = x;
                grafo[x, y].y = y;

            }

        }

        //inicializando o Nodo para cada posição do vetor.
        for (int x = 0; x < mapSizeX; x++){
            for (int y = 0; y < mapSizeY; y++){

                //Adcionando a esquerda.
                if (x > 0)
                    grafo[x, y].vizinhos.Add(grafo[x - 1, y]);

                //Adcionando a direita.
                if (x < mapSizeX - 1)
                    grafo[x, y].vizinhos.Add(grafo[x + 1, y]);

                //Adcionando para baixo.
                if (y > 0)
                    grafo[x, y].vizinhos.Add(grafo[x, y - 1]);

                //Adcionando para cima.
                if (y < mapSizeY - 1)
                    grafo[x, y].vizinhos.Add(grafo[x, y + 1]);

            }
        }
    }





    void instanciarMapa(){
        for (int x = 0; x < mapSizeX; x++){
            for (int y = 0; y < mapSizeY; y++){

                //tt vai receber o numero da posição de cada tile.
                TipoTile tt = tipoTile[tiles[x, y]];

                //Instaciando o mapa.
                //Utilizando o System.Serializable, ele já atribui valor "0,1,2,3" a nossos tilePrefabs no inspector.
                GameObject map = (GameObject)Instantiate(tt.tilePrefab, new Vector3(x, y, 0), Quaternion.identity);

                //tc será nosso tile clicavel, e ira receber todo o nosso mapa, mais os componentes do script "Tile Clicavel".
                TileClicavel tc = map.GetComponent<TileClicavel>();

                //Tile clicavel irá receber cada posição da nossa matriz.
                tc.tileX = x;
                tc.tileY = y;
                //O mapa de tc será toda a nossa clase TileMapa.
                tc.mapa = this;

            }
        }
    }





    //Retorna a posição no mundo.
    public Vector3 coodernada(int x, int y){
        return new Vector3(x, y, 0);
    }





    public void Dijkstra(int x, int y){

        //Verificando se o tile é andavel
        //Se não for, retorna, ou seja, é um tile não andavel.
        //"tipoTile" ira retornar para "tt" o tipo de cada tile, incluindo se ele é andavel ou não.
        TipoTile tt = tipoTile[tiles[x, y]];
        if (tt.andavel == false)
            return;


        //limpando os caminhos antigos
        player.GetComponent<Objeto>().caminhoAtual = null;


        //Estruturas usadas no Dijkstra.
        Dictionary<Nodo, float> dist = new Dictionary<Nodo, float>();
        Dictionary<Nodo, Nodo> anterior = new Dictionary<Nodo, Nodo>();


        //Lista de nodos não visitados.
        List<Nodo> Nvisitados = new List<Nodo>();

        //Posição atual do player.
        Nodo inicio = grafo[player.GetComponent<Objeto>().tileX, player.GetComponent<Objeto>().tileY];


        //Tile alvo;
        Nodo alvo = grafo[x, y];


        //Inicializando os "vetores" distancia e anterior.
        dist[inicio] = 0;
        anterior[inicio] = null;


        //inicializando todos os vertices a uma distancia inifinita.
        foreach (Nodo vert in grafo){
            if (vert != inicio){
                dist[vert] = Mathf.Infinity;
                anterior[vert] = null;
            }

            //Adciono os vertices a lista de nodos não visitados.
            Nvisitados.Add(vert);
        }



        //Enquanto a lista de nodos não visitados não for vazia.
        while (Nvisitados.Count > 0){

            //"u" será o nodo não visitado com a menor distancia
            Nodo u = null;
            
         
            foreach (Nodo menorDist in Nvisitados){
                //O "u" será null em nossa primeira iteração; depois disso, podemos ter outros nodos com uma distancia menor.
                if (u == null || dist[menorDist] < dist[u])
                    u = menorDist;
            }


            //Se o "u" for igual ao nosso alvo, sair do while.
            if (u == alvo){
                break;
            }


            //Remove "u" dos nodos não visitados.
            Nvisitados.Remove(u);

            //Para cada vertice na adjascencia de "u". Lembre-se que são os vizinhos que ligam um nodo ao outro.
            //Por isso eles são as adjascencias.
            foreach (Nodo vert in u.vizinhos){
               //"altura" irá receber o custo para chegar até o outro nodo.
                float altura = dist[u] + custoTile(vert.x, vert.y);
                //Se a "altura" for menor que a distancia até o vertice.
                if (altura < dist[vert]){
                    //distancia até o vertice recebe a altura.
                    dist[vert] = altura;
                    //e o anterior ao vertice recebe o "u", que é o menor caminho.
                    anterior[vert] = u;
                }
            }
        }

        //Agora, o "vetor" anterior, descreve a rota de menor caminho do alvo até o inicio.


        if (anterior[alvo] == null){
            return; 
            //sem rota para o alvo.
        }

        //Será o caminho do player até o alvo.
        //Instaciando o caminho atual.
        List<Nodo> caminhoAtual = new List<Nodo>();

        //O nodo atual começa no mesmo ponto de onde queremos chegar.
        //Pois vamos usar ele, para fazer o caminho inverso até chegar no nosso nodo inicio.
        Nodo atual = alvo;


        // percorrendo o "anterior" e adcionando para o caminho.
        while (atual != null){
            //Adcionando o atual a nosso caminho.
            caminhoAtual.Add(atual);
            //O nodo "atual" agora será o nodo anterior a ele, assim podemos traçar a rota até o caminho atual.
            atual = anterior[atual];
        }


        //Agora o caminho atual descreve uma rota do nosso alvo para nosso inicio.
        //Invertendo.
        caminhoAtual.Reverse();

        //A cada chamada, o Dijkstra gerará um caminho para nosso player.
        //Atualizando o caminho atual do player.
        player.GetComponent<Objeto>().caminhoAtual = caminhoAtual;

    }

}
