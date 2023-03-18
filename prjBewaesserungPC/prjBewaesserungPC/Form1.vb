Imports System.Data.SqlTypes
Imports System.IO.Ports

Public Class Form1
    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        For Each AvailableSerialPorts As String In SerialPort1.GetPortNames()

            ComboBox1.Items.Add(AvailableSerialPorts)

            ComboBox1.Text = AvailableSerialPorts

            SerialPort1.ReadTimeout = 5000

            Button1.Visible = True
            Button2.Visible = False
        Next
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        SerialPort1.BaudRate = "9600"

        SerialPort1.PortName = ComboBox1.SelectedItem

        Button1.Visible = False
        Button2.Visible = True

        If SerialPort1.IsOpen = False Then
            SerialPort1.Open()
        End If

        Timer1.Enabled = True
    End Sub

    Private Sub Button2_Click_1(sender As Object, e As EventArgs) Handles Button2.Click
        If SerialPort1.IsOpen = True Then
            SerialPort1.Close()
        End If


        Button1.Visible = True
        Button2.Visible = False

        Timer1.Enabled = False
    End Sub

    Public TIME As Double = 0
    Private Sub Timer1_Tick_1(sender As Object, e As EventArgs) Handles Timer1.Tick
        If SerialPort1.IsOpen = True Then
            Dim ReceivedMessage As String
            ReceivedMessage = SerialPort1.ReadLine

            Dim items() As String = ReceivedMessage.Split(","c)

            Label1.Text = "Temp: " + items(0) + "°C"
            Label2.Text = "Erdfeucht." + items(1) + "%"
            Label3.Text = "Helligkeit." + items(2) + " LUX"
            Label4.Text = "Luftfeucht." + items(3) + "%"

            If Debug.Checked Then
                Label5.Text = ReceivedMessage
            Else Label5.Text = ""
            End If

            If items(4) = 1 Then
                CheckedListBox1.SetItemChecked(0, True)
            Else CheckedListBox1.SetItemChecked(0, False)
            End If

            If items(5) = 1 Then
                CheckedListBox1.SetItemChecked(1, True)
            Else CheckedListBox1.SetItemChecked(1, False)
            End If

            If items(6) = 1 Then
                CheckedListBox1.SetItemChecked(2, True)
            Else CheckedListBox1.SetItemChecked(2, False)
            End If
            Chart1.Series(0).Points.AddXY(TIME, items(0))
            Chart1.Series(1).Points.AddXY(TIME, items(1))
            Chart1.Series(2).Points.AddXY(TIME, items(2))
            Chart1.Series(3).Points.AddXY(TIME, items(3))
            TIME = TIME + 4
        End If
    End Sub
End Class
