//
//  ContentView.swift
//  C++
//
//  Created by qt on 2024/2/26.
//

import SwiftUI

struct ContentView: View {
    @Binding var document: C__Document

    var body: some View {
        TextEditor(text: $document.text)
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView(document: .constant(C__Document()))
    }
}
