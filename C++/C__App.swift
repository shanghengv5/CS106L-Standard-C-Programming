//
//  C__App.swift
//  C++
//
//  Created by qt on 2024/2/26.
//

import SwiftUI

@main
struct C__App: App {
    var body: some Scene {
        DocumentGroup(newDocument: C__Document()) { file in
            ContentView(document: file.$document)
        }
    }
}
