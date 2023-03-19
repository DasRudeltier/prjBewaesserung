<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Das Formular überschreibt den Löschvorgang, um die Komponentenliste zu bereinigen.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Wird vom Windows Form-Designer benötigt.
    Private components As System.ComponentModel.IContainer

    'Hinweis: Die folgende Prozedur ist für den Windows Form-Designer erforderlich.
    'Das Bearbeiten ist mit dem Windows Form-Designer möglich.  
    'Das Bearbeiten mit dem Code-Editor ist nicht möglich.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim ChartArea10 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend10 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series37 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series38 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series39 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim Series40 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.GroupBox1 = New System.Windows.Forms.GroupBox()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.CheckedListBox1 = New System.Windows.Forms.CheckedListBox()
        Me.GroupBox2 = New System.Windows.Forms.GroupBox()
        Me.Debug = New System.Windows.Forms.CheckBox()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.GroupBox1.SuspendLayout()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'SerialPort1
        '
        Me.SerialPort1.PortName = "COM3"
        Me.SerialPort1.ReadBufferSize = 8192
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Button2)
        Me.GroupBox1.Controls.Add(Me.Button1)
        Me.GroupBox1.Controls.Add(Me.ComboBox1)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(312, 99)
        Me.GroupBox1.TabIndex = 2
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Verbindung zu Controller herstellen"
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(177, 59)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(121, 29)
        Me.Button2.TabIndex = 2
        Me.Button2.Text = "Trennen"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(12, 59)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(121, 29)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "Verbinden"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Location = New System.Drawing.Point(12, 25)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(286, 28)
        Me.ComboBox1.TabIndex = 0
        Me.ComboBox1.Text = "Verfügbare Com Ports"
        '
        'Timer1
        '
        Me.Timer1.Interval = 500
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(8, 101)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(140, 20)
        Me.Label1.TabIndex = 4
        Me.Label1.Text = "Warten auf Daten."
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(188, 101)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(0, 20)
        Me.Label2.TabIndex = 5
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(8, 121)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(0, 20)
        Me.Label3.TabIndex = 6
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(188, 121)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(0, 20)
        Me.Label4.TabIndex = 7
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.TopRight
        '
        'Chart1
        '
        ChartArea10.Name = "ChartArea1"
        Me.Chart1.ChartAreas.Add(ChartArea10)
        Legend10.Name = "Legend1"
        Me.Chart1.Legends.Add(Legend10)
        Me.Chart1.Location = New System.Drawing.Point(12, 168)
        Me.Chart1.Name = "Chart1"
        Series37.ChartArea = "ChartArea1"
        Series37.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series37.Legend = "Legend1"
        Series37.Name = "Temperatur (°C)"
        Series38.ChartArea = "ChartArea1"
        Series38.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series38.Legend = "Legend1"
        Series38.Name = "Erdfeuchtigkeit (%)"
        Series39.ChartArea = "ChartArea1"
        Series39.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series39.Legend = "Legend1"
        Series39.Name = "Helligkeit (LUX)"
        Series40.ChartArea = "ChartArea1"
        Series40.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line
        Series40.Legend = "Legend1"
        Series40.Name = "Luftfeuchtigkeit (%)"
        Me.Chart1.Series.Add(Series37)
        Me.Chart1.Series.Add(Series38)
        Me.Chart1.Series.Add(Series39)
        Me.Chart1.Series.Add(Series40)
        Me.Chart1.Size = New System.Drawing.Size(909, 426)
        Me.Chart1.TabIndex = 8
        Me.Chart1.Text = "Chart1"
        '
        'CheckedListBox1
        '
        Me.CheckedListBox1.Enabled = False
        Me.CheckedListBox1.FormattingEnabled = True
        Me.CheckedListBox1.Items.AddRange(New Object() {"Lüfter", "UV/Licht", "Pumpe"})
        Me.CheckedListBox1.Location = New System.Drawing.Point(12, 25)
        Me.CheckedListBox1.Name = "CheckedListBox1"
        Me.CheckedListBox1.Size = New System.Drawing.Size(310, 73)
        Me.CheckedListBox1.TabIndex = 9
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.CheckedListBox1)
        Me.GroupBox2.Controls.Add(Me.Label1)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Controls.Add(Me.Label2)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Location = New System.Drawing.Point(330, 12)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(328, 153)
        Me.GroupBox2.TabIndex = 10
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Info / Einstellung"
        '
        'Debug
        '
        Me.Debug.AutoSize = True
        Me.Debug.Location = New System.Drawing.Point(12, 600)
        Me.Debug.Name = "Debug"
        Me.Debug.Size = New System.Drawing.Size(83, 24)
        Me.Debug.TabIndex = 11
        Me.Debug.Text = "Debug"
        Me.Debug.UseVisualStyleBackColor = True
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(21, 129)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(0, 20)
        Me.Label5.TabIndex = 12
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(102, 603)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(0, 20)
        Me.Label6.TabIndex = 13
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(9.0!, 20.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.Window
        Me.ClientSize = New System.Drawing.Size(939, 631)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Debug)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.Chart1)
        Me.Controls.Add(Me.GroupBox1)
        Me.MaximumSize = New System.Drawing.Size(961, 687)
        Me.MinimumSize = New System.Drawing.Size(961, 687)
        Me.Name = "Form1"
        Me.Text = "Bewässerungssystem JaMaTi | Main"
        Me.GroupBox1.ResumeLayout(False)
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents Button2 As Button
    Friend WithEvents Button1 As Button
    Friend WithEvents ComboBox1 As ComboBox
    Friend WithEvents Timer1 As Timer
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Chart1 As DataVisualization.Charting.Chart
    Friend WithEvents CheckedListBox1 As CheckedListBox
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents Debug As CheckBox
    Friend WithEvents Label5 As Label
    Friend WithEvents Label6 As Label
End Class
