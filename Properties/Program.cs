using System.Runtime.InteropServices.ComTypes;
using Delta_Dent;
using Delta_Dent.Components;


string directoryTempImg = "tempImg";
string directoryUploads = "uploads";

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddRazorComponents()
    .AddInteractiveServerComponents();

// Configure Kestrel server options
builder.WebHost.ConfigureKestrel(serverOptions =>
{
    serverOptions.Limits.MaxRequestBodySize = 104857600; // 100 MB
});

// Add services to the container.
builder.Services.Configure<Microsoft.AspNetCore.Http.Features.FormOptions>(options =>
{
    options.MultipartBodyLengthLimit = 104857600; // 100 MB
});
// Configure the HTTP request pipeline and the rest of your app...

var app = builder.Build();

// Enable HSTS and HTTPS redirection in production
if (!builder.Environment.IsDevelopment())
{
    builder.Services.AddHsts(options =>
    {
        options.Preload = true;
        options.IncludeSubDomains = true;
        options.MaxAge = TimeSpan.FromDays(120);
    });

    builder.Services.AddHttpsRedirection(options =>
    {
        options.RedirectStatusCode = StatusCodes.Status308PermanentRedirect;
        options.HttpsPort = 443;
    });
}
app.UseHttpsRedirection();

app.UseStaticFiles();
app.UseAntiforgery();

app.MapRazorComponents<App>()
    .AddInteractiveServerRenderMode();

if (!Directory.Exists(directoryTempImg))
{
    Directory.CreateDirectory(directoryTempImg);
}

if (!Directory.Exists(directoryUploads))
{
    Directory.CreateDirectory(directoryUploads);
}



app.Run();