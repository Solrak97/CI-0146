import java.util.HashMap;

%%

%public
%class CLex
%standalone

%unicode

%{
  int lines = 0;
  int cycles = 0;
  int conditionals = 0;
  int comments = 0;
  HashMap<String, Integer> typeMap = new HashMap<String, Integer>();

%}

%{
  void set_map(String t){
    if(typeMap.containsKey(t)){
      typeMap.put(t, typeMap.get(t) + 1);
    }
    else{
      typeMap.put(t, 1);
    }
  }

  void printMap(){
    typeMap.entrySet().forEach(entry -> {
    System.out.println("Type: " + entry.getKey() + " " + "Entries: " + entry.getValue());
});
  }
%}

%%

int {
  set_map(yytext());
}

for | while {
  	cycles++;
}

if | else | "else if" | switch {
  conditionals++;
}

"\n" {
  lines++;
}

"//" | "/*" {
  comments++;
}

<<EOF>> {
  System.out.println("\n");
  System.out.println("Luis Carlos Quesada - B65580");
  System.out.println("Gianfranco Bagnarello Hernández - B70866");
  System.out.println("Isaac Herrera - B43332");
  System.out.println("\n");
  System.out.println("Cantidad de lineas de codigo: " + lines);
  System.out.println("\n");
  System.out.println("Types:");
  printMap();
  System.out.println("\n");
  System.out.println("Cantidad de ciclos: " + cycles);
  System.out.println("\n");
  System.out.println("Cantidad de condicionales: " + conditionals);
  System.out.println("\n");
  System.out.println("Cantidad de comentarios: " + comments);
  System.exit(0);
}