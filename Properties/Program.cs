using Blazored.LocalStorage;
using Delta_Dent.Components;

string directoryTempImg = "tempImg";
string directoryUploads = "Images";

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
ConfigureServices(builder.Services);

// Configure Kestrel server options
ConfigureKestrel(builder.WebHost);

// Configure form options
ConfigureFormOptions(builder.Services);

var app = builder.Build();

// Configure middleware
ConfigureMiddleware(app, builder.Environment);

EnsureDirectoriesExist(directoryTempImg, directoryUploads);

app.Run();

void ConfigureServices(IServiceCollection services)
{
    services.AddRazorComponents().AddInteractiveServerComponents();
    services.AddBlazoredLocalStorage(config => config.JsonSerializerOptions.WriteIndented = true);
}

void ConfigureKestrel(IWebHostBuilder webHostBuilder)
{
    webHostBuilder.ConfigureKestrel(serverOptions =>
    {
        serverOptions.Limits.MaxRequestBodySize = 104857600; // 100 MB
    });
}

void ConfigureFormOptions(IServiceCollection services)
{
    services.Configure<Microsoft.AspNetCore.Http.Features.FormOptions>(options =>
    {
        options.MultipartBodyLengthLimit = 104857600; // 100 MB
    });
}

void ConfigureMiddleware(WebApplication app, IWebHostEnvironment environment)
{
    // Enable HSTS and HTTPS redirection in production
    if (!environment.IsDevelopment())
    {
        app.UseHsts();
        app.UseHttpsRedirection();
    }

    app.UseStaticFiles();
    app.UseAntiforgery();

    app.MapRazorComponents<App>().AddInteractiveServerRenderMode();
}

void EnsureDirectoriesExist(params string[] directories)
{
    foreach (var directory in directories)
    {
        if (!Directory.Exists(directory))
        {
            Directory.CreateDirectory(directory);
        }
    }
}
