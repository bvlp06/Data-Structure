using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//Faz com que os atributos da classe apareçam no inspector.
//Possibilita a criação de objetos da mesma classe.
[System.Serializable]

public class TipoTile {

    
	public string nome;
    //O cubo que sera colocado 
	public GameObject tilePrefab;
    //O custo do movimento até essa tile
    public float custoMov;
    //Mato é andavel, terra não
    public bool andavel = true;

}
