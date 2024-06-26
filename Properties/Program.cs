using System.Runtime.InteropServices.ComTypes;
using Delta_Dent;
using Delta_Dent.Components;


string directoryTempImg = "tempImg";
string directoryUploads = "uploads";

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddRazorComponents()
    .AddInteractiveServerComponents();

var app = builder.Build();

// Configure the HTTP request pipeline.
if (!app.Environment.IsDevelopment())
{
    app.UseExceptionHandler("/Error", createScopeForErrors: true);
    // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
    app.UseHsts();
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