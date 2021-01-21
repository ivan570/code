<%@ Page Title="" Language="C#" MasterPageFile="~/librarian/librarian.Master" AutoEventWireup="true" CodeBehind="sendmessage.aspx.cs" Inherits="final_done_now.librarian.sendmessage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="c1" runat="server">
     <asp:Repeater ID="r1" runat="server" >
        <HeaderTemplate>
            <table class="table">
                <thead>
                    <tr>
                        <th>image</th>
                        <th>first name</th>
                        <th>last name</th>
                        <th>enrollment no</th>
                        <th>username</th>
                        <th>email</th>
                        <th>Contact</th>
                        <th>Status</th>
                        <th>message</th>
                    </tr>
                </thead>
                <tbody>
        </HeaderTemplate>
        <ItemTemplate>
            <tr>
                <td><img src="../<%#Eval("student_img") %>" height="100" width="100"/></td>
                <td><%#Eval("firstname") %></td>
                <td><%#Eval("lastname") %></td>
                <td><%#Eval("enrollment_no") %></td>
                <td><%#Eval("username") %></td>
                <td><%#Eval("email") %></td>
                <td><%#Eval("contact") %></td>
                <td><%#Eval("approved") %></td>
                <td><a href="communication.aspx?username=<%# Eval("username") %>">Send message</a></td>
            </tr>
        </ItemTemplate>
        <FooterTemplate>
                </tbody>
            </table>
        </FooterTemplate>
    </asp:Repeater>
</asp:Content>
