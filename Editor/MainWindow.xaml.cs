using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using Microsoft.Build.Evaluation;
using Microsoft.Build.Execution;

namespace Editor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        System.Diagnostics.Process buildProcess;
        System.Diagnostics.Process gameProcess;


        public MainWindow()
        {
            InitializeComponent();
        }

        private void Build_Click(object sender, RoutedEventArgs e)
        {
            string projectFile = @"C:\dev\repos\rayoflight\engine\engine.vcxproj";
            ProjectCollection pc = new ProjectCollection();
            Dictionary<string, string> GlobalProperty = new Dictionary<string, string>();
            GlobalProperty.Add("Configuration", "Debug");
            GlobalProperty.Add("Platform", "x86");
            BuildRequestData buildRequest = new BuildRequestData(projectFile, GlobalProperty, null, new string[] { "Build" }, null);
            BuildResult buildResult = BuildManager.DefaultBuildManager.Build(new BuildParameters(pc), buildRequest);
            this.BuildStatus.Text = buildResult.OverallResult.ToString();
        }

        private void Start_Click(object sender, RoutedEventArgs e)
        {
            string file = "C:\\dev\\repos\\rayoflight\\engine\\bin\\x86\\Debug\\engine.exe";
            string command = "";

            var startInfo = new System.Diagnostics.ProcessStartInfo(file, command);
            gameProcess = System.Diagnostics.Process.Start(startInfo);
        }
    }
}
