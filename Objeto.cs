using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Objeto : MonoBehaviour {

	public int tileX;
	public int tileY;
    public TileMapa mapa;
    public AudioClip som;
    AudioSource audio;
    
    //No começo, nosso caminho será null, pois ainda não existe um caminho a ser seguido.
    //Caminho que será gerado pelo Djikstra.
    public List<Nodo> caminhoAtual = null;

    //Porem, a cada chamada do dijkstra, será gerado um novo caminho atual para ser percorrido.

    void Start(){

        //Tocador da musica.
        audio = GetComponent<AudioSource>();
    }



    //A cada click em um tile, a função Djikstra sera chamada, como tambem a função update.
    void Update(){

        desenharCaminho();
    }



    public void desenharCaminho(){

        if (caminhoAtual != null){

            int i = 0;

            //Percorrendo todos os nodos do caminho atual para desenhar o caminho.
            //Enquanto o caminho tiver mais que um nodo a ser percorrido.
            while (i < caminhoAtual.Count - 1){
                
                //Inicio sera o nodo inicial, o fim será proximo nodo a ser desenhado.
                Vector3 inicio = mapa.coodernada(caminhoAtual[i].x, caminhoAtual[i].y) + new Vector3(0, 0, -0.75f);
                Vector3 fim = mapa.coodernada(caminhoAtual[i + 1].x, caminhoAtual[i + 1].y) + new Vector3(0, 0, -0.75f);

                //Função para desenhar o caminho.
                DrawLine(inicio, fim, Color.blue, 0.9f);

                i++;
            }

                //Se o audio não estiver tocando, toca a musica de novo.
                if (audio.isPlaying == false){
                    audio.clip = som;
                    audio.Play();
                
            }
        }
    }



    public void Mover(){

        if (caminhoAtual == null)
            return;
        

        //Removendo o primeiro/ultimo nodo visitado do caminho
        caminhoAtual.RemoveAt(0);

        //Atualizando a posição no mundo
        tileX = caminhoAtual[0].x;
        tileY = caminhoAtual[0].y;

        //Pegando o proximo nodo que será o "0" e movendo para a posição
        transform.position = Vector3.Lerp(transform.position, mapa.coodernada(caminhoAtual[0].x, caminhoAtual[0].y), 1f);

     
        if (caminhoAtual.Count == 1){
            //Sobrou so um tile em nosso caminho
            //Limpando o caminho
            caminhoAtual = null;

        }
    }



   
    public void DrawLine(Vector3 inicio, Vector3 fim, Color cor, float duracao){

        GameObject linha = new GameObject();
        linha.transform.position = inicio;
        linha.AddComponent<LineRenderer>();
        LineRenderer renderizar = linha.GetComponent<LineRenderer>();
        renderizar.material = new Material(Shader.Find("Particles/Alpha Blended Premultiply"));
        renderizar.SetColors(cor, cor);
        renderizar.SetWidth(0.160f, 0.160f);
        renderizar.SetPosition(0, inicio);
        renderizar.SetPosition(1, fim);
        GameObject.Destroy(linha, duracao);

    }

}
