using Microsoft.AspNetCore.Components;
using Microsoft.JSInterop;

namespace Delta_Dent;

///<summary>
///This class is used to switch pages and move files in the application.
///</summary>
public class PageSwitcher
{
    private static NavigationManager navigator;
    
    /// <summary>
    /// Initializes a new instance of the <see cref="PageSwitcher"/> class.
    /// </summary>
    /// <param name="navigationManager"></param>
    public PageSwitcher(NavigationManager navigationManager)
    {
        navigator = navigationManager;
    }
    
    /// <summary>
    /// funtion thas switch the page and copy the file in the tempImg folder
    /// </summary>
    /// <param name="id">id of the image</param>
    /// <param name="path">path where the file will be saved</param>
    [JSInvokable]
    public static Task SwitchPage(string id,String path)
    {
        // Get the path to the directory where the image is located
        var imagesDirectoryPath = Path.Combine(path, "Images");

        // Get the path to the image file
        var imagePath = Path.Combine(imagesDirectoryPath, id);
        
        // Check if the image file exists
        if (File.Exists(imagePath))
        {   
            // Get the path to the directory where you want to copy the image
            var tempImagesDirectoryPath = Path.Combine(path, "tempImg");

            // Ensure the directory exists
            Directory.CreateDirectory(tempImagesDirectoryPath);

            // Get the path to the new image file
            var newImagePath = Path.Combine(tempImagesDirectoryPath, "temp.png");

            // Copy the image file and overwrite if the file already existss
            File.Copy(imagePath, newImagePath, true);
        }

        return Task.CompletedTask;
    }
}