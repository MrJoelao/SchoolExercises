using System.Runtime.InteropServices.ComTypes;
using Blazored.LocalStorage;
using Delta_Dent;
using Delta_Dent.Components;
using Microsoft.AspNetCore.Http;

string directoryTempImg = "tempImg";
string directoryUploads = "Images";

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

builder.Services.AddBlazoredLocalStorage(config => config.JsonSerializerOptions.WriteIndented = true);

var app = builder.Build();

// Enable HSTS and HTTPS redirection in production
if (!builder.Environment.IsDevelopment())
{
    app.UseHsts();
    app.UseHttpsRedirection();
}

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