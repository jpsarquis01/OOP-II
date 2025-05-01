// See https://aka.ms/new-console-template for more information

using Assigment3;

List<Product> products = new List<Product>();

Book book = new Book("TinTin", "Tralalero tralala", "adventure", 2025);
Electronics electronics = new Electronics("Toshiba", "XBook", 3);
Clothing clothing = new Clothing("Cotton", "red", 30);

products.Add(book);
products.Add(electronics);
products.Add(clothing);

foreach (var product in products)
{
    product.DisplayInfo();
}