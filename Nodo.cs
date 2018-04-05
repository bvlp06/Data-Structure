using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//Cada tile do nosso mapa sera representado por um nodo.
public class Nodo{
    
    //Vizinhos sera a lista de nodos que ligara todos os tiles entre si.
    //Então "vizinhos" será a adjascencia de cada tile/nodo.
    public List<Nodo> vizinhos;
    public int x;
    public int y;


    //No construtor de "Nodo", vizinhos já sera instaciada.
    public Nodo(){
        vizinhos = new List<Nodo>();
    }

}