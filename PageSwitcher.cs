using Microsoft.AspNetCore.Components;
using Microsoft.JSInterop;

namespace Delta_Dent;

public class PageSwitcher
{
    private static NavigationManager navigator;

    public PageSwitcher(NavigationManager navigationManager)
    {
        navigator = navigationManager;
    }

    [JSInvokable]
    public static Task SwitchPage(string id,String path)
    {
        Console.Write("\nsto entrando nello switchingg");
        // Get the path to the directory where the image is located
        var imagesDirectoryPath = Path.Combine(path, "Images");

        // Get the path to the image file
        var imagePath = Path.Combine(imagesDirectoryPath, id);
        
        Console.Write("\npath img: " + imagePath);
        // Check if the image file exists
        if (File.Exists(imagePath))
        {   
            Console.Write("\nl'immagine esiste -> procedo");
            // Get the path to the directory where you want to copy the image
            var tempImagesDirectoryPath = Path.Combine(path, "tempImg");

            // Ensure the directory exists
            Directory.CreateDirectory(tempImagesDirectoryPath);

            // Get the path to the new image file
            var newImagePath = Path.Combine(tempImagesDirectoryPath, "temp.png");

            // Copy the image file and overwrite if the file already exists
            Console.Write("sto per copiare "+ imagePath + " in " + newImagePath);
            File.Copy(imagePath, newImagePath, true);
        }

        return Task.CompletedTask;
    }
}