/* Author: Donna Walker     Class: CSIT-1520/Lab 10
 * Description: JavaFX GUI application that works like a shopping cart system
 * for an online book store. Reads in books from text file named Bookprices.txt. 
 * Provides a menu with an exit option under file, and a Help menu with an About
 * submenu. Allows customer to select and deselect books from the cart using 
 * buttons. Provides a running total in subtotal, tax and total. At checkout,
 * performs one-click checkout with additional information provided on the run screen.
 * 
 */
package Lab4;



import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextField;
import javafx.scene.effect.Reflection;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCombination;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.Text;
import javafx.stage.Modality;
import javafx.stage.Stage;

public class WalkerDMenu_lab4 extends Application {
  
  //Declares variables with potential to be accessed through multiple methods. 
  ArrayList<String> bookArray = new ArrayList<>();
  ListView<String> listStore = new ListView<>();
  ObservableList<String> itemsStore;
  ListView<String> listCart = new ListView<>();
  ObservableList<String> itemsCart;
  double subDouble;
  String subTotal;
  String tax;
  String total;
  private TextField tfSubtotal = new TextField(); 
  private TextField tfTax = new TextField();
  private TextField tfTotal = new TextField();
  
  @Override // Override the start method in the Application class
  public void start(Stage primaryStage) { 
      
    try {
      // Uses BufferedReader object
      BufferedReader br = new BufferedReader(new FileReader(new File("Bookprices.txt")));
	bookArray = new ArrayList<>();
        String line = null;
        //Reads lines from Bookprices.txt into ArrayList bookArray.
        while ((line = br.readLine())!=null){
	  bookArray.add(line);
	}
	br.close();
    } 
    catch (FileNotFoundException e) {
      System.out.println("File not exists or insufficient rights");
      e.printStackTrace();
    } 
    catch (IOException e) {
      System.out.println("An exception occured while reading the file");
      e.printStackTrace();
    }

    //Declares MenuBar, File and Help Menus 
    MenuBar menuBar = new MenuBar();    
    Menu menuFile = new Menu("File");
    Menu menuHelp = new Menu("Help");
    
    //Adds Menus to MenuBar.   
    menuBar.getMenus().addAll(menuFile, menuHelp);
    
    //Declares Exit MenuItem
    MenuItem menuItemExit = new MenuItem("Exit");
    menuFile.getItems().add(menuItemExit);
    //Declares About Menu Item	
    MenuItem menuItemAbout = new MenuItem("About");
    menuHelp.getItems().add(menuItemAbout);
    //Define short cut keys for exit and about MenuItems
    menuItemExit.setAccelerator(
    KeyCombination.keyCombination("Ctrl+C"));
    menuItemAbout.setAccelerator(
    KeyCombination.keyCombination("Ctrl+A"));
    
    //Puts MenuBar in vBox0 container.
    VBox vBox0 = new VBox(10);
    vBox0.getChildren().addAll(menuBar);    


    //Declares base Node  
    BorderPane base = new BorderPane();
    
    //Displays bookstore title with a reflection property
    Label lblTitle = new Label("Books R Us");
    lblTitle.setFont(Font.font("Verdana", FontPosture.ITALIC, 36));
    Reflection r = new Reflection();
    r.setFraction(0.7f);
    lblTitle.setEffect(r);
    lblTitle.setTranslateY(-80);
    
    //Builds buttons for moving items between store and shopping cart.
    Button buyAll = new Button(">>");
    Button buySelect = new Button(">");
    Button cancelSelect = new Button ("<");
    Button cancelAll = new Button ("<<");
    
    //Creates container and sets container properties to place page title and 
    //buttons into the center of screen.
    VBox vBox1 = new VBox(10);
    vBox1.getChildren().addAll(lblTitle,buyAll,buySelect,cancelSelect,cancelAll);
    vBox1.setAlignment(Pos.CENTER);
    vBox1.setPadding(new Insets(10));
    
      
    //Declares vbox1 to hold ListView for Store. Store is populated with items
    //read in from Bookprices.txt. Viewlist is set up to take multiple selections.
    VBox vbox1 = new VBox(10);
    Text txtStore = new Text("Store");
    txtStore.setFont(Font.font("Times New Roman, 36"));
    txtStore.setFill(Color.BLUE);
    itemsStore = FXCollections.observableArrayList(bookArray);
    listStore.setItems(itemsStore);
    listStore.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
    listStore.setMaxHeight(250);
    vbox1.getChildren().addAll(txtStore,listStore);
    vbox1.setAlignment(Pos.CENTER_LEFT);
    vbox1.setPadding(new Insets(10));
    
    //Declares vbox2 to hold ListView for Shopping Cart 
    //Sets ListView to multiple selection and initialized
    //as empty
    //StackPane pane2 = new StackPane();    
    VBox vbox2 = new VBox(20);
    Text txtCart = new Text("Shopping Cart");
    txtCart.setFont(Font.font("Times New Roman, 36"));
    txtCart.setFill(Color.BLUE);
    vbox2.setAlignment(Pos.CENTER_RIGHT);
    
    //Sets up empty cart with no items in it.
    itemsCart = FXCollections.observableArrayList();
    listCart.setItems(itemsCart);
    listCart.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
    listCart.setMaxHeight(250);
    vbox2.getChildren().addAll(txtCart,listCart);
    vbox2.setAlignment(Pos.CENTER);
    vbox2.setPadding(new Insets(10));
    
    //Sets up gridpane container to display subtotal, tax, total and checkout button.
    GridPane gp1 = new GridPane();
    gp1.setAlignment(Pos.CENTER);
    gp1.setPadding(new Insets(6.5,8.5,10.5,12.5));
    gp1.setHgap(3.5);
    gp1.setVgap(3.5);
    
    //Place tfSubtotal, tfTax, tfTotal and btCkOut into a gridpane container
    gp1.add(new Label("Subtotal"), 0, 0);
    gp1.add(tfSubtotal, 1, 0);
    tfSubtotal.setText("0.00");
    tfSubtotal.setEditable(false);
    gp1.add(new Label("Tax"), 0, 1);
    gp1.add(tfTax, 1, 1);
    tfTax.setText("0.00");
    tfTax.setEditable(false);
    gp1.add(new Label("Total"), 0, 2);
    gp1.add(tfTotal, 1, 2);
    tfTotal.setText("0.00");
    tfTotal.setEditable(false);
    Button btCkOut = new Button("Checkout");
    gp1.add(btCkOut, 1, 3);
    GridPane.setHalignment(btCkOut, HPos.LEFT);
     
    //Displays menu at the top, title and buttons at center, store ListView at left,
    //shopping cart ListView at right, and checkout GridPane at bottom of BorderPane.
    base.setTop(vBox0);
    base.setCenter(vBox1);
    base.setLeft(vbox1);
    base.setRight(vbox2);
    base.setBottom(gp1);
    Scene scene1 = new Scene(base, 1000, 700);
    scene1.setFill(Color.BLUE);
    
    
    // Assigns handlers to all the menuItem and button nodes.
    menuItemExit.setOnAction(e -> System.exit(0));
    
    //About menu item is set to close because I could not get this function to work.
    menuItemAbout.setOnAction(e -> showAbout());
    buyAll.setOnAction(e -> buyingAll());
    buySelect.setOnAction(e -> selectSome());
    cancelSelect.setOnAction(e -> cancelSome());
    cancelAll.setOnAction(e -> cancelAll());
    btCkOut.setOnAction(e -> checkOut());
    
    //Sets title to primary stage, places scene1 into primaryStage and shows window.    
    primaryStage.setTitle("Books are Us");     
    primaryStage.setScene(scene1); 
    primaryStage.show(); 
           
  }
    //Handles action button (>>) moving all the items to cart and calling methods to 
    //tabulate price based on provided Bookprices.txt from assignment. Attempted to 
    //split string in ObservableList to get prices, but they did not respond to a split.
    private void buyingAll(){
      subDouble = 0.00;
      listCart.getSelectionModel().clearSelection(0);  
      listCart.getSelectionModel().getSelectedItems();
      itemsCart.addAll(itemsStore);
      itemsStore.removeAll(itemsStore);
      listStore.getSelectionModel().clearSelection();
      subDouble = getSubtotal(itemsCart);
      displaySub(subDouble);
            
    }
     
    //Uses provided book titles and prices to tabulate subtotal.
    private double getSubtotal(ObservableList<String> menuList){
      int i = 0;
      subDouble = 0.00;
    
      for (String string1 : menuList){
        if (string1.contains("did"))
          subDouble = subDouble + 11.95;
        if (string1.contains("History"))
          subDouble = subDouble + 14.50;
        if (string1.contains("Learn"))
          subDouble = subDouble + 29.95;
        if (string1.contains("Stress"))
          subDouble = subDouble + 18.50;
        if (string1.contains("Mozart"))
          subDouble = subDouble + 18.95;  
            
      }
      return subDouble;
    }  
    
    //Simulates formatting subtotal, tax and total using Math round.
    //Attempted to use DecimalFormat, but was not successful in formatting string.
    private void displaySub(double subDouble){
      DecimalFormat myFormat = new DecimalFormat("$###,###.00");  
      double tempDouble = subDouble*100;
      double temp2Double = Math.round(tempDouble);
      subDouble = temp2Double/100;
      double taxDouble = subDouble * .09;
      double tempTax1 = taxDouble * 100;
      double tempTax2 = Math.round(tempTax1);
      double subTax = tempTax2/100;
      subTotal = myFormat.format(subDouble) + "";
      tax = myFormat.format(subTax) + "";
      double totalDouble = subDouble + subTax;
      double tempTotal1 = totalDouble * 100;
      double tempTotal2 = Math.round(tempTotal1);
      double finalTotal = tempTotal2/100;
      total = myFormat.format(finalTotal) + ""; 
      tfSubtotal.setText(subTotal);
      tfTax.setText(tax);
      tfTotal.setText(total);
    }
               
  //Adds selected items (>) to cart and retabulates totals.
    private void selectSome(){
      ObservableList temp = FXCollections.observableArrayList(listStore.getSelectionModel().getSelectedItems());  
      itemsStore.removeAll(temp);
      //itemsCart.add();
      itemsCart.addAll(temp);
      listStore.getSelectionModel().clearSelection();
      subDouble = getSubtotal(itemsCart);
      displaySub(subDouble);
    }
    //Remove selected items (<) from cart and retabulates totals.
    private void cancelSome(){
      ObservableList temp1 = FXCollections.observableArrayList(listCart.getSelectionModel().getSelectedItems());  
      itemsCart.removeAll(temp1);
      //itemsCart.add();
      itemsStore.addAll(temp1);
      listCart.getSelectionModel().clearSelection();
      subDouble = getSubtotal(itemsCart);
      displaySub(subDouble);
    }
      
    //Removes all books from cart (<<) and clears totals.
    private void cancelAll(){
      listCart.getSelectionModel().getSelectedItems();
      itemsStore.addAll(itemsCart);
      itemsCart.removeAll(itemsCart);
      listCart.getSelectionModel().clearSelection();
      subDouble = getSubtotal(itemsCart);
      displaySub(subDouble);
    }
    //Completes purchase, closing application and provides user feedback in the run window.
    private void checkOut(){  
      System.out.println("Thank you for using one-click checkout."); 
      System.out.println("Credit Card on file: ****-****-****-2234");
      System.out.println("Preferred shopper: Your items will be shipped tomorrow for free!");
      System.out.println("Your final total was: " + total);
      System.exit(0);
       
    }        
    //Method still in progress. Could not figure out how to make it work. Tried many ways.
    //Needed to figure out how to change focus between scenes, so main window would not shutdown. 
    private void showAbout(){
      
      Stage aboutStage = new Stage();
      Label aboutLbl = new Label("About Us");
      TextField newtxt1 = new TextField("Version 2.0 - Our Shopping Cart");
      newtxt1.setEditable(false);
      VBox about1 = new VBox();
      Image img = new Image(WalkerDMenu_lab4.class.getResourceAsStream("download.jpg"));
      ImageView imgView = new ImageView(img);
      about1.getChildren().addAll(imgView, aboutLbl, newtxt1);
      Scene scene2 = new Scene(about1, 200, 200);
      aboutStage.setScene(scene2);
      aboutStage.initModality(Modality.WINDOW_MODAL);
      aboutStage.show();
    }
      
    
  
        
  
  /**
   * Main method  
   */
  public static void main(String[] args) {
    launch(args);
  }
}
