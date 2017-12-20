/*---------------------------------------------------------------------------------------------
 *  Copyright (c) Microsoft Corporation. All rights reserved.
 *  Licensed under the MIT License. See License.txt in the project root for license information.
 *--------------------------------------------------------------------------------------------*/

function runas(command, callback) {
    require('../build/Release/windows_runas.node').runas(command, callback);
}

module.exports = runas;